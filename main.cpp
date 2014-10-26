
#include "json_generator.h"


int main(int argc, char **argv) {

  cout<<"TEST - START"<<endl;


  string fname = "hello";
  json_generator jg( fname );


  // TEST 1
  jg.open_object();
  
  jg.add_key( "hello" );
  jg.add_value( "world" );  

  jg.add_key( "some_key" );
  jg.add_value( "some_value" );  

  jg.add_key( "array_cat_names" );
  jg.open_array();
  jg.close_array();

  jg.add_key( "array_dog_names" );
  jg.open_array();
  jg.close_array();  

  
  jg.add_key( "some_name" );
  jg.open_object();
  jg.add_key( "hello_again" );
  jg.add_value( "world_again" );  

  jg.add_key( "some_key_again" );
  jg.add_value( "some_value_again" );  
 
  jg.add_key( "array_cat_names_again" );
  std::vector<string > vec_strs;
  vec_strs.clear();
  vec_strs.push_back( "cam" );
  vec_strs.push_back( "eric" );
  vec_strs.push_back( "vick" );
  jg.add_array_value( vec_strs );

  jg.add_key( "array_numbers" );
  jg.open_array();
  std::vector<int > vec_ints;
  vec_ints.clear();
  int some_num = 0;
  vec_ints.push_back( some_num+=1 );
  vec_ints.push_back( some_num+=1 );
  vec_ints.push_back( some_num+=1 );
  jg.add_value( vec_ints );
  jg.close_array();  
  jg.close_object();



  jg.close_object();


  cout<<"----Formatted content string START: "<<endl;
  cout<<jg.get_contents_string()<<endl;
  cout<<"----Formatted content string STOP: "<<endl;
  cout<<"----Organisation string START: "<<endl;
  cout<<jg.get_organisation_string()<<endl;
  cout<<"----Organisation string START: "<<endl;
  jg.print();


  
  // TEST 2
  /*
    {
      "menu": {
        "id": "file",
        "value": "File",
        "popup": {
          "menuitem": [ {"value": "New", "onclick": "CreateNewDoc()"},{"value": "Open", "onclick": "OpenDoc()"},{"value": "Close", "onclick": "CloseDoc()"} ]
        }
      } 
    }
  */
  jg.clear_contents();

  jg.open_object();
  
  jg.add_key( "menu" );
  jg.open_object();
  jg.add_key("id");
  jg.add_value("file");
  jg.add_key("valie");
  jg.add_value("File");
  jg.add_key("popup");
  jg.open_object();
  jg.add_key("menuitem");
  

  jg.open_array();

  jg.open_object();
  jg.add_key("value");
  jg.add_value("New");
  jg.add_key("onclick");
  jg.add_value("CreateNewDoc()");
  jg.close_object();

  jg.open_object();
  jg.add_key("value");
  jg.add_value("Open");
  jg.add_key("onclick");
  jg.add_value("OpenDoc()");
  jg.close_object();

  jg.open_object();
  jg.add_key("value");
  jg.add_value("Close");
  jg.add_key("onclick");
  jg.add_value("CloseDoc()");
  jg.close_object();

  jg.close_array();

  jg.close_object();
  jg.close_object();


  jg.close_object();

  cout<<"----Formatted content string START: "<<endl;
  cout<<jg.get_contents_string()<<endl;
  cout<<"----Formatted content string STOP: "<<endl;
  cout<<"----Organisation string START: "<<endl;
  cout<<jg.get_organisation_string()<<endl;
  cout<<"----Organisation string START: "<<endl;
  jg.print();







  cout<<"TEST - STOP"<<endl;

  return 0;
}
