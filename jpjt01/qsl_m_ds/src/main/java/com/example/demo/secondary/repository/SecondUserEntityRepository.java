package com.example.demo.secondary.repository;


import com.example.demo.secondary.model.UserEntity;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface SecondUserEntityRepository extends CrudRepository<UserEntity, String>{
    
}
