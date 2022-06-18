package ac.sict.G8_AMS.Controller;

import ac.sict.G8_AMS.domain.Album;
import ac.sict.G8_AMS.domain.NoticeMain;
import ac.sict.G8_AMS.domain.NoticeTo;
import ac.sict.G8_AMS.domain.XOX;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;

@Controller
@RequestMapping("/coo")
public class CooController {

    @RequestMapping("/home")
    public String home(Model model) throws IOException {
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        List<NoticeMain> findNoticeMain = sqlSession.selectList("findNoticeMain");
        for (NoticeMain main:findNoticeMain){
            XOX xox = new XOX();
            xox.setXoxID(main.getCap());
            XOX findXoxUseID = (XOX) sqlSession.selectList("findXoxUseID", xox).get(0);
            main.setAfter(findXoxUseID.getTeam()+" "+findXoxUseID.getXoxName());
        }
        model.addAttribute("list",findNoticeMain);
        return "home.jsp";
    }

    @RequestMapping("/manager")
    public String save(Model model) throws IOException {
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        List<Album> albums = sqlSession.selectList("userMapper.findAlbum");
        List<XOX> xoxes = sqlSession.selectList("userMapper.findCap");
        List<String> teams = sqlSession.selectList("userMapper.findTeam");
        sqlSession.close();
        model.addAttribute("albums",albums);
        model.addAttribute("caps",xoxes);
        model.addAttribute("teams",teams);
        return "addAct.jsp";
    }

    @RequestMapping("/addAct")
    public String save2(Model model,HttpServletRequest request) throws IOException {
        request.setCharacterEncoding("UTF-8");
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        String album = request.getParameter("album");
        String cap = request.getParameter("cap");
        String dateAndTime = request.getParameter("datetime");
        String id = album+cap+dateAndTime;
        String team = request.getParameter("team");
        if(album.isEmpty()||cap.isEmpty()||dateAndTime.isEmpty()||team.isEmpty()){
            return "home";
        }
        Album album1 = new Album();
        album1.setAlbumID(album);
        String albumName  = String.valueOf(sqlSession.selectList("findAlbumUseID",album1).get(0));
        String actName = "SNH48 "+team+"《"+albumName+"》主题公演";
        NoticeMain noticeMain = new NoticeMain(id, dateAndTime, actName, team, cap, album, false);
        sqlSession.insert("insertNoticeMain",noticeMain);
        String content = dateAndTime + " "+ actName;
        NoticeTo noticeTo = new NoticeTo(id,cap, 1, content, 0);
        sqlSession.insert("insertNoticeTo", noticeTo);
        sqlSession.commit();
        sqlSession.close();
        return "home";
    }
}
