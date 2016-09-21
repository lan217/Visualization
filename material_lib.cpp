#include "material_lib.h"
#include <QDebug>
QStringList MaterialLib::materialNameList;
MaterialLib* MaterialLib::mInstance;
QList<MaterialLib::Material*> MaterialLib::materialList;
MaterialLib::MaterialLib()
{
    for (int i = 0;i < 5;i++) {
        Material* material = new Material();
        material->setDestiny(i);
        material->setEmissivity(i);
        QMap<float, float> map;
        map.insert(200, 2);
        map.insert(400, 2);
        map.insert(500, 2);
        material->setMaterialName("不锈钢" + QString::number(i));
        material->setTmpCpMap(map);
        material->setTmpLambdaMap(map);
        materialList.append(material);
    }


    for (int i = 0;i < materialList.size();i++) {
        this->materialNameList << materialList.at(i)->getMaterialName();
    }
}
MaterialLib::Material* MaterialLib::getMaterial(int index)
{
    if (index < materialList.size()) {

        return materialList.at(index);
    }

    return NULL;
}

MaterialLib* MaterialLib::getInstance()
{
    if (mInstance == NULL) {
        mInstance = new MaterialLib();
    }

    return mInstance;

}

QStringList MaterialLib::getMaterial()
{
    return materialNameList;
}

