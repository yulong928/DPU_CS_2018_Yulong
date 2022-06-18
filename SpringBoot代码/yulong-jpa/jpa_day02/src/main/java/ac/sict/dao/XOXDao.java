package ac.sict.dao;

import ac.sict.domain.XOX;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.JpaSpecificationExecutor;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;

import java.util.Date;
import java.util.List;

public interface XOXDao extends JpaRepository<XOX,String>, JpaSpecificationExecutor<XOX> {

    @Query(value = "from XOX where xoxName = ?")
    public XOX findJpql(String name);

    @Query(value = "from XOX where xoxID = ? and xoxName = ?")
    public XOX findXOXUseIdAndName(String id,String name);

    @Query(value = "update XOX set birthday=?2 where xoxID=?1")
    @Modifying
    public void updateXOX(String id,Date date);

    @Query(value = "select * from XOX",nativeQuery = true)
    public List<Object[]> findSql();

    @Query(value = "select * from XOX where xoxName like ?1",nativeQuery = true)
    public List<Object[]> findSqlUseName(String name);

    public XOX findByXoxName(String name);

    public List<XOX> findByXoxNameLike(String name);
}
