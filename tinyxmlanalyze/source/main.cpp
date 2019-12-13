#include <stdio.h>
#include <string.h>
#include <vector>
#include "tinyfunc.h"

using namespace std;


struct Node
{
	int id;
	char when[32];
	char who[32];
	char where[32];
};

vector<Node> nodes;
vector<Node> Node_read;

//想容器添加东西
void addNode(int id, const char* when, const char* who, const char* where)
{
	Node n;
	n.id = id;
	strcpy(n.when, when);
	strcpy(n.who, who);
	strcpy(n.where, where);
	nodes.push_back(n);
}

//保存到xml文件中
int save()
{
	TiXmlDocument xml_doc;
	//添加声明
	xml_doc.LinkEndChild(new TiXmlDeclaration("1.0", "GBK", ""));
	//添加根元素
	TiXmlElement* xml_root = new TiXmlElement("root");
	xml_doc.LinkEndChild(xml_root);
	//根元素下面添加节点
	for (unsigned int i = 0; i < nodes.size(); i++)
	{
		Node& n = nodes[i];
		//创建一个节点
		TiXmlElement* xml_node = new TiXmlElement("node");
		xml_root->LinkEndChild(xml_node);
		//创建第一个子节点
		if (1)
		{
			addChile(xml_node, "id", n.id);
			addChile(xml_node, "when", n.when);
			addChile(xml_node, "where", n.where);
			addChile(xml_node, "who", n.who);
		}
	}
	//保存文件
	xml_doc.SaveFile("aaaa.xml");
	return 0;
}




//生成xml文件
int test1()
{
	TiXmlDocument xml_doc;
	//添加XML声明
	xml_doc.LinkEndChild(new TiXmlDeclaration("1,0", "GBK", ""));
	//添加根元素
	TiXmlElement* xml_root = new TiXmlElement("root");
	xml_doc.LinkEndChild(xml_root);

	//在根元素添加其他子元素
	if (1)
	{
		//添加host
		TiXmlElement* xml_child = new TiXmlElement("host");
		xml_root->LinkEndChild(xml_child);
		//添加文档内容
		xml_child->LinkEndChild(new TiXmlText("127.0.0.1"));
		//设置属性
		xml_child->SetAttribute("checked", "true");
		xml_child->SetAttribute("station", 1001);
	}
	//嵌套子元素
	if (1)
	{
		TiXmlElement* xml_client = new TiXmlElement("client");
		xml_root->LinkEndChild(xml_client);

		TiXmlElement* xml_clientName = new TiXmlElement("name");
		xml_clientName->LinkEndChild(new TiXmlText("andy"));
		xml_client->LinkEndChild(xml_clientName);

		TiXmlElement* xml_clientId = new TiXmlElement("id");
		xml_clientId->LinkEndChild(new TiXmlText("20190608"));
		xml_client->LinkEndChild(xml_clientId);

		//保存文件
		xml_doc.SaveFile("example.xml");
		//或者转成string
		//string text;
		//text << xml_doc;
		return 0;
	}
}


#if 0
//解析xml文件
int test2()
{
	//解析xml
	TiXmlDocument xml_doc;
	if (!xml_doc.LoadFile("example.xml"))
	{
		return -1;
	}
	//根节点
	TiXmlElement* xml_root = xml_doc.RootElement();
	if (xml_root == NULL)
	{
		return -1;
	}
	//获取元素的文本与属性
	if (1)
	{
		TiXmlElement* xml_host = xml_root->FirstChildElement("host");
		const char* text = xml_host->GetText();
		const char* aCheckedd = xml_host->Attribute("checked");
		const char* aStation = xml_host->Attribute("station");
		printf("text:%s , checked:%s , station:%s", text, aCheckedd, aStation);
	}
	if (1)
	{
		TiXmlElement* xml_client = xml_root->FirstChildElement("client");

		TiXmlElement* xml_name = xml_client->FirstChildElement("name");
		TiXmlElement* xml_id = xml_client->FirstChildElement("id");
	}
	return 0;
}
//解析多个子节点
int test3()
{
	//开始解析
	TiXmlDocument xml_doc;
	if (!xml_doc.LoadFile("aaaa.xml"))
	{
		return -1;
	}
	//获取根元素
	TiXmlElement* xml_root = xml_doc.RootElement();
	if (xml_root == NULL)
	{
		return -1;
	}
	TiXmlElement* xml_note = xml_root->FirstChildElement("node");
	while (xml_note)
	{
		Node n;
		//获取他们的值
		TiXmlElement* xml_id = xml_note->FirstChildElement("id");
		const char* id = xml_id->GetText();
		n.id = atoi(id);
		TiXmlElement* xml_when = xml_note->FirstChildElement("when");
		strcpy(n.when, xml_when->GetText());
		TiXmlElement* xml_where = xml_note->FirstChildElement("where");
		strcpy(n.where, xml_where->GetText());
		TiXmlElement* xml_who = xml_note->FirstChildElement("who");
		strcpy(n.who, xml_who->GetText());
		Node_read.push_back(n);
		//只想下一个兄弟节点
		xml_note = xml_note->NextSiblingElement();
	}

}
#endif

int main()
{
	test1();
	//addNode(1, "2016-1-23 10:00", "Wang", "吃饭");
	//addNode(2, "2016-1-21 20:00", "Jiang", "看电影");
	//addNode(3, "2016-1-20 9:00", "Li", "去博物馆");

	//save();
	//test3();
	//遍历vector
	for (int i = 0; i < Node_read.size(); i++)
	{
		Node n = Node_read[i];
		printf("id:%d \n, when:%s \n , where:%s \n, who:%s\n", n.id, n.when, n.where, n.who);
	}
	printf("保存成功！\n");
	return 0;
}

