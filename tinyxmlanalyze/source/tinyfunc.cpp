#include "tinyfunc.h"


/*
函数名： addChile
参数：   parent----父节点
         node----节点名称
		 value----节点值
返回值：无
*/
void addChile(TiXmlElement * parent, const char* node, int value)
{
	//创建节点
	TiXmlElement* xml_node = new TiXmlElement(node);
	//将int转为char
	char buf[32];
	sprintf(buf, "%d", value);
	xml_node->LinkEndChild(new TiXmlText(buf));
	parent->LinkEndChild(xml_node);

}

void addChile(TiXmlElement * parent, const char* node, const char* value)
{
	//创建节点
	TiXmlElement* xml_node = new TiXmlElement(node);
	//将int转为char
	xml_node->LinkEndChild(new TiXmlText(value));
	parent->LinkEndChild(xml_node);
}