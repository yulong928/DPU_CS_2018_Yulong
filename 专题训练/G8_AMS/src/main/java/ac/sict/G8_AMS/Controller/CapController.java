package ac.sict.G8_AMS.Controller;


import ac.sict.G8_AMS.domain.*;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;

@Controller
@RequestMapping("/cap")
public class CapController {
    @RequestMapping("/setActForXox")
    public String setActForXox(Model model, HttpServletRequest request) throws IOException {
        request.setCharacterEncoding("UTF-8");
        String xoxID = request.getParameter("xoxID");
        String actID = request.getParameter("actID");
        XOX xox = new XOX();
        xox.setXoxID(xoxID);
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        XOX xoxUseID = (XOX) sqlSession.selectList("findXoxUseID", xox).get(0);
        List<XOX> findXoxUseTeam = sqlSession.selectList("findXoxUseTeam", xoxUseID);
        model.addAttribute("xoxes",findXoxUseTeam);
        NoticeMain noticeMain = new NoticeMain();
        noticeMain.setId(actID);
        NoticeMain findMainNoticeUseID = (NoticeMain) sqlSession.selectList("findMainNoticeUseID", noticeMain).get(0);
        List<Music> findMusicFromNoticdeAlbum = sqlSession.selectList("findMusicFromNoticdeAlbum", findMainNoticeUseID);
        model.addAttribute("musics",findMusicFromNoticdeAlbum);
        model.addAttribute("act",findMainNoticeUseID);
        model.addAttribute("xox",xoxID);
        return "addActForXox.jsp";
    }

    @RequestMapping("/setActMenu")
    public String setActMenu(Model model, HttpServletRequest request, HttpServletResponse response) throws IOException {
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        String actId = request.getParameter("actId");
        NoticeMain noticeMain = new NoticeMain();
        noticeMain.setId(actId);
        String findAlbumFromActUseId = String.valueOf(sqlSession.selectList("findAlbumFromActUseId", noticeMain).get(0));
        Album album = new Album();
        album.setAlbumID(findAlbumFromActUseId);
        List<Music> findMusicFromAlbum = sqlSession.selectList("findMusicFromAlbum", album);
        for (Music music:findMusicFromAlbum){
            for (int i=1;i<= music.getNumber();i++)
            {
                String xoxId = request.getParameter(music.getMusicID() + "." + i);
                ArrangeMusicToAct arrangeMusicToAct = new ArrangeMusicToAct(actId, music.getMusicID(), i, xoxId);
                if(!xoxId.equals("null"))
                {
                    sqlSession.insert("insertNoticeMusic",arrangeMusicToAct);
                }
            }
        }
        List<String> findXoxFromNoticeMusic = sqlSession.selectList("findXoxFromNoticeMusic", noticeMain);
        NoticeMain findMainNoticeUseID = (NoticeMain) sqlSession.selectList("findMainNoticeUseID", noticeMain).get(0);
        String notice = findMainNoticeUseID.getDateAndTime() + " "+findMainNoticeUseID.getActName();
        for (String xoxID:findXoxFromNoticeMusic){
            NoticeTo noticeTo = new NoticeTo(noticeMain.getId(),xoxID, 2, notice, 0);
            sqlSession.insert("insertNoticeTo",noticeTo);
        }
        noticeMain.setCapStatue(true);
        sqlSession.update("updateCapSet",noticeMain);
        NoticeTo noticeTo = new NoticeTo();
        noticeTo.setNoticeID(actId);
        noticeTo.setType(1);
        sqlSession.update("updateCapSet2",noticeTo);
        sqlSession.commit();
        sqlSession.close();
        String xoxID = request.getParameter("xoxID");
        return "redirect:../searchMsg?xoxID="+xoxID;
    }
}
