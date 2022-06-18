package ac.sict.dao;

import ac.sict.domain.Music;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.JpaSpecificationExecutor;

public interface MusicDao extends JpaSpecificationExecutor<Music>, JpaRepository<Music,String> {
}
