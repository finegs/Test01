package com.example.demo.secondary.model;

import static com.querydsl.core.types.PathMetadataFactory.*;

import com.querydsl.core.types.dsl.*;

import com.querydsl.core.types.PathMetadata;
import javax.annotation.processing.Generated;
import com.querydsl.core.types.Path;


/**
 * QSecondTestEntity is a Querydsl query type for SecondTestEntity
 */
@Generated("com.querydsl.codegen.DefaultEntitySerializer")
public class QSecondTestEntity extends EntityPathBase<SecondTestEntity> {

    private static final long serialVersionUID = -95216606L;

    public static final QSecondTestEntity secondTestEntity = new QSecondTestEntity("secondTestEntity");

    public final StringPath column = createString("column");

    public final StringPath id = createString("id");

    public QSecondTestEntity(String variable) {
        super(SecondTestEntity.class, forVariable(variable));
    }

    public QSecondTestEntity(Path<? extends SecondTestEntity> path) {
        super(path.getType(), path.getMetadata());
    }

    public QSecondTestEntity(PathMetadata metadata) {
        super(SecondTestEntity.class, metadata);
    }

}

