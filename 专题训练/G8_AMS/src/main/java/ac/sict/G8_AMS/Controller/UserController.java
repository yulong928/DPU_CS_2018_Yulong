package ac.sict.G8_AMS.Controller;

import ac.sict.G8_AMS.domain.*;
import com.sun.org.apache.xpath.internal.operations.Mod;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;
import java.io.IOException;
import java.io.InputStream;
import java.util.List;

@Controller
public class UserController {

    @RequestMapping("/login")
    public String save(Model model,HttpServletRequest request) throws IOException {
        request.setCharacterEncoding("UTF-8");
        String xoxID = request.getParameter("xoxID");
        String xoxName = request.getParameter("xoxName");
        if(xoxID.isEmpty()||xoxName.isEmpty())
        {
            System.out.println("输入为空！");
            return "redirect:index.jsp";
        }
        if(xoxID.equals("48")&&xoxName.equals("manager")){
            return "redirect:coo/home";
        }
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        XOX xox = new XOX();
        xox.setXoxID(xoxID);
        List<XOX> xoxes = sqlSession.selectList("findXoxUseID", xox);
        if(xoxes.isEmpty()||!(xoxes.get(0).getXoxName().equals(xoxName)))
        {
            System.out.println("ID或姓名错误");
            return "redirect:index.jsp";
        }
        XOX xox1 = xoxes.get(0);
        model.addAttribute("xox",xox1);
        List<NoticeTo> findMsgFromNoticeToUseXOX = sqlSession.selectList("findMsgFromNoticeToUseXOX", xox1);
        model.addAttribute("count",findMsgFromNoticeToUseXOX.size());
        sqlSession.close();
        return "home.jsp";
    }



    @RequestMapping("/searchMsg")
    public String searchMsgForXox(Model model,HttpServletRequest request) throws IOException {
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        String xoxID = request.getParameter("xoxID");
        XOX xox = new XOX();
        xox.setXoxID(xoxID);
        List<XOX> xoxes = sqlSession.selectList("findXoxUseID", xox);
        model.addAttribute("xox", xoxes.get(0));
        List<NoticeTo> findNoticeUseID = sqlSession.selectList("findNoticeUseID", xoxes.get(0));
        model.addAttribute("notice",findNoticeUseID);
        sqlSession.close();
        return "/message.jsp";
    }

    @RequestMapping("/searchAct")
    public String searchAct(Model model,HttpServletRequest request) throws IOException {
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        String xoxID = request.getParameter("xoxID");
        String actID = request.getParameter("actID");
        String sendXoxId = request.getParameter("searchID");
        ArrangeMusicToAct arrangeMusicToAct = new ArrangeMusicToAct();
        arrangeMusicToAct.setActID(actID);
        arrangeMusicToAct.setXoxID(sendXoxId);
        List<ArrangeMusicToAct> findNoticeMusicForXox = sqlSession.selectList("findNoticeMusicForXox", arrangeMusicToAct);
        model.addAttribute("list",findNoticeMusicForXox);
        for (ArrangeMusicToAct act : findNoticeMusicForXox){
            Music music = new Music();
            music.setMusicID(act.getMusicID());
            Music findMusicFromId = (Music) sqlSession.selectList("findMusicFromId", music).get(0);
            act.setMusicName(findMusicFromId.getMusicName());
        }
        return "actList.jsp";
    }

    @RequestMapping("/applyForLeave")
    public String applyForLeave(Model model,HttpServletRequest request) throws IOException {
        String xoxID = request.getParameter("xoxID");
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        XOX xox = new XOX();
        xox.setXoxID(xoxID);
        List<NoticeTo> findNoticeUseID = sqlSession.selectList("findUncheckNoticeUseID", xox);
        List<XOX> findAll = sqlSession.selectList("findAll");
        model.addAttribute("actList",findNoticeUseID);
        model.addAttribute("xoxList",findAll);
        model.addAttribute("xoxID",xoxID);
        return "applyForLeave.jsp";
    }

    @RequestMapping("/applyCheck")
    public String applyCheck(Model model,HttpServletRequest request) throws IOException {
        String xoxID = request.getParameter("xoxID");
        String actID = request.getParameter("actID");
        String acceptXoxID = request.getParameter("xoxToLeave");
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        XOX xox = new XOX();xox.setXoxID(xoxID);
        XOX findXoxUseID = (XOX) sqlSession.selectList("findXoxUseID", xox).get(0);
        NoticeMain noticeMain = new NoticeMain();noticeMain.setId(actID);
        NoticeMain findMainNoticeUseID = (NoticeMain) sqlSession.selectList("findMainNoticeUseID", noticeMain).get(0);
        NoticeTo noticeTo = new NoticeTo(acceptXoxID, 3, findXoxUseID.getTeam()+" "+findXoxUseID.getXoxName()+"向你发送"+findMainNoticeUseID.getDateAndTime()+" "+findMainNoticeUseID.getActName()+"代班申请", 0,actID, xoxID);
        sqlSession.insert("insertNoticeToApply",noticeTo);
        noticeTo.setAcceptXoxId(xoxID);
        sqlSession.update("applyLeaveToXOX",noticeTo);
        sqlSession.commit();
        sqlSession.close();
        return "redirect:searchMsg?xoxID="+xoxID;
    }

    @RequestMapping("/acceptApply")
    public String acceptApply(Model model,HttpServletRequest request) throws IOException {
        String xoxID = request.getParameter("xoxID");
        String actID = request.getParameter("actID");
        String requestID = request.getParameter("searchID");
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        XOX xox = new XOX();xox.setXoxID(xoxID);
        XOX findXoxUseID = (XOX) sqlSession.selectList("findXoxUseID", xox).get(0);
        NoticeMain noticeMain = new NoticeMain();noticeMain.setId(actID);
        NoticeMain findMainNoticeUseID = (NoticeMain) sqlSession.selectList("findMainNoticeUseID", noticeMain).get(0);
        NoticeTo noticeTo1 = new NoticeTo(actID, requestID, 4, findXoxUseID.getTeam()+" "+findXoxUseID.getXoxName()+"接受了您"+findMainNoticeUseID.getDateAndTime()+" "+findMainNoticeUseID.getActName()+"的代班请求", 1);
        sqlSession.insert("insertNoticeTo",noticeTo1);
        NoticeTo noticeTo = new NoticeTo(xoxID,2,"",1,actID,requestID);
        sqlSession.update("acceptApplyForRequest",noticeTo);
        noticeTo.setType(3);
        sqlSession.update("acceptApplyForResponse",noticeTo);
        sqlSession.commit();
        sqlSession.close();
        return "redirect:searchMsg?xoxID="+xoxID;
    }


    @RequestMapping("check")
    public String check(Model model,HttpServletRequest request) throws IOException {
        String xoxID = request.getParameter("xoxID");
        String actID = request.getParameter("actID");
        InputStream resourceAsStream = Resources.getResourceAsStream("sqlMapConfig.xml");
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(resourceAsStream);
        SqlSession sqlSession = sqlSessionFactory.openSession();
        NoticeTo noticeTo = new NoticeTo(actID, xoxID, 2, "", 1);
        sqlSession.update("updateCapSet3", noticeTo);
        sqlSession.commit();
        sqlSession.close();
        return "redirect:searchMsg?xoxID="+xoxID;
    }
}
