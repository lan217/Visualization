#ifndef MATERIAL_LIB_H
#define MATERIAL_LIB_H
#include <QFile>
#include <QStringList>
#include <QList>
#include <QMap>

class MaterialLib
{

public:
    MaterialLib();
    class Material;
    static MaterialLib *getInstance();
    QStringList getMaterial();
    Material* getMaterial(int index);

    class Material {
    private:
        QString materialName;
        float destiny;
        float emissivity;
        QMap<float, float> tmpLambdaMap;
        QMap<float, float> tmpCpMap;
    public:
        Material()
        {

        }

        QString getMaterialName()
        {
            return this->materialName;
        }

        void setMaterialName(const QString &name)
        {
            this->materialName = name;
        }

        float getDestiny()
        {
            return this->destiny;
        }

        void setDestiny(float destiny)
        {
            this->destiny = destiny;
        }

        float getEmissivity()
        {
            return this->emissivity;
        }

        void setEmissivity(float emissivity)
        {
            this->emissivity = emissivity;
        }

        QMap<float, float> getTmpLambdaMap()
        {
            return this->tmpLambdaMap;
        }

        QMap<float, float> getTmpCpMap()
        {
            return this->tmpCpMap;
        }

        void setTmpLambdaMap(QMap<float, float> tmpLambdaMap)
        {
            this->tmpLambdaMap = tmpLambdaMap;
        }

        void setTmpCpMap(QMap<float, float> tmpCpMap)
        {
            this->tmpCpMap = tmpCpMap;
        }
    };


private:
    static MaterialLib *mInstance;
    static QList<Material*> materialList;
    static QStringList materialNameList;

};

#endif // MATERIAL_LIB_H
