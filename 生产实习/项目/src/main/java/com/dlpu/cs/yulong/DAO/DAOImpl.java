package com.dlpu.cs.yulong.DAO;
import com.dlpu.cs.yulong.JDBC.DataSource;
import com.dlpu.cs.yulong.POJO.*;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
public class DAOImpl {
    private DataSource dataSource = new DataSource();
    public boolean checkStudent(String id,String name){
        try {
            Connection connection = dataSource.getConnection();
            Statement statement = connection.createStatement();
            String SQL = "select distinct stu_name from examList where stu_id = " + id;
            final ResultSet rs = statement.executeQuery(SQL);
            if (rs.next()){
                if (rs.getString("stu_name").equals(name)){
                    return true;
                }
            }
        } catch (SQLException | ClassNotFoundException throwables) {
            throwables.printStackTrace();
        }
        return false;
    }
    public List<ExamList> search(String id) throws SQLException, ClassNotFoundException {
        List<ExamList> lists = new ArrayList<>();
        Connection connection = dataSource.getConnection();
        Statement statement = connection.createStatement();
        String SQL = "select cou_id,cou_name,statue from examList where stu_id = " + id;
        final ResultSet rs = statement.executeQuery(SQL);
        while (rs.next()){
            String cou_id = rs.getString("cou_id");
            String cou_name = rs.getString("cou_name");
            boolean statue = rs.getBoolean("statue");
            ExamList list = new ExamList(cou_id,cou_name,statue);
            lists.add(list);
        }
        return lists;
    }
    public int update(String id,String cou_id,boolean statue) throws SQLException, ClassNotFoundException {
        String SQL;
        Connection connection = dataSource.getConnection();
        Statement statement = connection.createStatement();
        if (!statue){
            SQL = "update examList set statue=true where stu_id = " + id +" and cou_id = " + cou_id;
        }else {
            SQL = "update examList set statue=false where stu_id = " + id +" and cou_id = " + cou_id;
        }
        final int rs = statement.executeUpdate(SQL);
        connection.commit();
        connection.close();
        return rs;
    }
    public List<CourseMsg> getCourseList() throws SQLException, ClassNotFoundException {
        List<CourseMsg> msgList = new ArrayList<>();
        List<CourseMsg> msgFinalList = new ArrayList<>();
        Connection connection = dataSource.getConnection();
        Statement statement = connection.createStatement();
        String SQL = "select distinct cou_id,cou_name from examList";
        ResultSet rs = statement.executeQuery(SQL);
        String cou_id;
        while (rs.next()){
            cou_id = rs.getString("cou_id");
            String cou_name = rs.getString("cou_name");
            CourseMsg msg = new CourseMsg(cou_id,cou_name);
            msgList.add(msg);
        }
        for (CourseMsg msg:msgList){
            SQL = "select count(*) from examList where cou_id = " + msg.getCourseID();
            ResultSet r1 = statement.executeQuery(SQL);
            if(r1.next())
            {
                msg.setAll_count(r1.getInt(1));
            }
            SQL = "select count(*) from examList where cou_id = " + msg.getCourseID() +" and statue = true";
            ResultSet r2 = statement.executeQuery(SQL);
            if(r2.next())
            {
                msg.setCheck_count(r2.getInt(1));
            }
            msgFinalList.add(msg);
        }
        return msgFinalList;
    }
    public List<ClassCourseMsg> getClassCourseList(String cou_id) throws SQLException, ClassNotFoundException {
        List<ClassCourseMsg> classCourseMsgs = new ArrayList<>();
        List<ClassCourseMsg> classFinalCourseMsgs = new ArrayList<>();
        Connection connection = dataSource.getConnection();
        Statement statement = connection.createStatement();
        String SQL = "select distinct class,room,date,time from examList where cou_id = "+cou_id;
        ResultSet rs = statement.executeQuery(SQL);
        while (rs.next()){
            ClassCourseMsg courseMsg = new ClassCourseMsg(rs.getString("class"));
            courseMsg.setRoom(rs.getString("room"));
            courseMsg.setDate(String.valueOf(rs.getDate("date")));
            courseMsg.setTime(rs.getString("time"));
            classCourseMsgs.add(courseMsg);
        }
        for (ClassCourseMsg msg:classCourseMsgs){
            SQL = "select count(*) from examList where cou_id = " + cou_id +" and class = \""+msg.getClassName()+"\"";
            ResultSet r1 = statement.executeQuery(SQL);
            if(r1.next())
            {
                msg.setAllNum(r1.getInt(1));
            }
            SQL = "select count(*) from examList where cou_id = " + cou_id +" and class = \""+msg.getClassName() +"\" and statue = true";
            System.out.println(SQL);
            ResultSet r2 = statement.executeQuery(SQL);
            if(r2.next())
            {
                msg.setCheckNum(r2.getInt(1));
            }
            classFinalCourseMsgs.add(msg);
        }
        return classCourseMsgs;
    }
    public List<ExamMsg> getExamMsgs(String id) throws SQLException, ClassNotFoundException {
        List<ExamMsg> examMsgs = new ArrayList<>();
        Connection connection = dataSource.getConnection();
        Statement statement = connection.createStatement();
        String SQL = "select cou_name,date,time,room from examList where statue=true and stu_id = "+id;
        ResultSet rs = statement.executeQuery(SQL);
        while (rs.next()){
            ExamMsg msg = new ExamMsg(rs.getString("cou_name"),rs.getString("date"),
                    rs.getString("time"),rs.getString("room"));
            examMsgs.add((msg));
        }
        return examMsgs;
    }
    public List<StuMsg> getStuMsgs(String id,String className) throws SQLException, ClassNotFoundException {
        List<StuMsg> stuMsgs = new ArrayList<>();
        Connection connection = dataSource.getConnection();
        Statement statement = connection.createStatement();
        String SQL = "select stu_id,stu_name,statue from examList where class=\""+className+"\" and cou_id = "+id;
        ResultSet rs = statement.executeQuery(SQL);
        while (rs.next()){
            StuMsg stuMsg = new StuMsg(rs.getString("stu_id"),rs.getString("stu_name"),rs.getBoolean("statue"));
            stuMsgs.add(stuMsg);
        }
        return stuMsgs;
    }
    public int CancelExam(String stu_id,String cou_id) throws SQLException, ClassNotFoundException {
        Connection connection = dataSource.getConnection();
        Statement statement = connection.createStatement();
        String SQL = "DELETE from examList where stu_id = "+stu_id+" and cou_id = "+cou_id;
        final int rs = statement.executeUpdate(SQL);
        connection.commit();
        connection.close();
        return rs;
    }
    public void InsertExam(String cou_id,String cou_name,String className) throws SQLException, ClassNotFoundException {
        List<StuMsg> msgs = new ArrayList<>();
        Connection connection = dataSource.getConnection();
        Statement statement = connection.createStatement();
        String SQL = "select distinct stu_id,stu_name from examList where class = \""+className+"\"";
        ResultSet rs = statement.executeQuery(SQL);
        while (rs.next()){
            StuMsg msg = new StuMsg(rs.getString("stu_id"),rs.getString("stu_name"),false);
            msgs.add(msg);
        }
        for (StuMsg msg : msgs){
            String SQL1 = "insert into examList(stu_id, stu_name, class, cou_id, cou_name, statue) values (\""+msg.getId()
                    +"\",\""+msg.getStu_name()+"\",\""+className+"\",\""+cou_id+"\",\""+cou_name+"\",false)";
            statement.executeUpdate(SQL1);
            connection.commit();
        }
        connection.close();
    }
}
