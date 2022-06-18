package ac.sict.dao;

import ac.sict.domain.XOX;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.JpaSpecificationExecutor;

public interface XOXDao extends JpaRepository<XOX,String>, JpaSpecificationExecutor<XOX> {
}
