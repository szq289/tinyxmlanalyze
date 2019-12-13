#include "tinyfunc.h"


/*
�������� addChile
������   parent----���ڵ�
         node----�ڵ�����
		 value----�ڵ�ֵ
����ֵ����
*/
void addChile(TiXmlElement * parent, const char* node, int value)
{
	//�����ڵ�
	TiXmlElement* xml_node = new TiXmlElement(node);
	//��intתΪchar
	char buf[32];
	sprintf(buf, "%d", value);
	xml_node->LinkEndChild(new TiXmlText(buf));
	parent->LinkEndChild(xml_node);

}

void addChile(TiXmlElement * parent, const char* node, const char* value)
{
	//�����ڵ�
	TiXmlElement* xml_node = new TiXmlElement(node);
	//��intתΪchar
	xml_node->LinkEndChild(new TiXmlText(value));
	parent->LinkEndChild(xml_node);
}