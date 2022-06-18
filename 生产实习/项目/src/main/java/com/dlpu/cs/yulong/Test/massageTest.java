package com.dlpu.cs.yulong.Test;

import com.dlpu.cs.yulong.DAO.DAOImpl;
import com.dlpu.cs.yulong.POJO.ClassCourseMsg;
import com.dlpu.cs.yulong.POJO.CourseMsg;
import org.junit.Test;

import java.sql.SQLException;
import java.util.List;

public class massageTest {

    private DAOImpl dao = new DAOImpl();
    @Test
    public void test1() throws SQLException, ClassNotFoundException {
        List<CourseMsg> msgList = dao.getCourseList();
        System.out.println(msgList);
    }
    @Test
    public void test2() throws SQLException, ClassNotFoundException {
        List<ClassCourseMsg> msgList = dao.getClassCourseList("010420001");
        for(ClassCourseMsg msg:msgList){
            System.out.println(msg);
        }
    }
}
