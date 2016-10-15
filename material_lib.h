#ifndef MATERIAL_LIB_H
#define MATERIAL_LIB_H
#include <QFile>
#include <QStringList>
#include <QList>
#include <QMap>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

class MaterialLib
{

public:
    MaterialLib();
    ~MaterialLib();
    class Material;
    static MaterialLib *getInstance();
    QMap<int, Material> getMaterialNameList();
    QMap<float, float> getTmpLambdaMap(int index);
    QMap<float, float> getTmpCpMap(int index);
    Material* getMaterial(int index);
    bool updateMaterialName(int index, const QString &name);
    bool updateMaterialProperty(int index, float destiny ,float emissivity);
    bool updateMaterialTmpLambdaMap(int index, QMap<float, float> tmpLambdaMap);
    bool updateMaterialTmpCpMap(int index, QMap<float, float> tmpCpMap);

    class Material {
    public:
        QString materialName;
        float destiny;
        float emissivity;
        int type;
    };


private:
    const static QString CREATE_MATERIAL_TABLE_SQL;
    const static QString CREATE_TMPLAMBDA_TABLE_SQL;
    const static QString CREATE_TMPCP_TABLE_SQL;
    static MaterialLib *mInstance;
    QSqlDatabase db;
};

#endif // MATERIAL_LIB_H
