
#include "../src/json_generator.h"


int main(int argc, char **argv) {

  cout<<"** CPPJSONGENERATOR - TEST - STOP"<<endl;


  string fname = "hello";
  json_generator jg( fname );


  // TEST 1
  /*
  {
    "hello": "world",
    "some_key": "some_value",
    "array_cat_names": [ ],
    "array_dog_names": [ "yager", "max"],
    "person": {
      "name": "cameron",
      "cat_names_again": [ "cam", "eric", "vick" ],
      "home_info": {
        "address":"987 some street avenue"
	"gps":123.456
      },
      "array_numbers": [ 1, 2, 3 ]
    }
  }
*/


  jg.open_object(); //start schema                 // {
  
  jg.add_key( "hello" );
  jg.add_value( "world" );                         //   "hello": "world",

  jg.add_pair( "some_key", "some_value" );  
  jg.add_key( "array_cat_names" );
  jg.open_array();
  jg.close_array();                                //   "array_cat_names": [ ],

  jg.add_key( "array_dog_names" );
  std::vector<string > vec_dogs;
  vec_dogs.push_back("yager");
  vec_dogs.push_back("max");
  jg.add_array_value( vec_dogs );                  //    "array_dog_names": [ "yager", "max"],
  
  jg.open_object( "peron" );                       //    "person": {
  jg.add_pair( "name", "cameron");                 //      "name": "cameron",
  jg.add_key( "array_cat_names_again" );
  std::vector<string > vec_strs;
  vec_strs.push_back( "cam" );
  vec_strs.push_back( "eric" );
  vec_strs.push_back( "vick" );
  jg.add_array_value( vec_strs );                  //      "cat_names_again": [ "cam", "eric", "vick" ],

  jg.open_object( "home_info" );                   //      "home_info": {
  jg.add_pair("address","987 some street avenue"); //        "address":"987 some street avenue"
  jg.add_pair("gps",123.456);                      // 	     "gps":123.456
  jg.close_object(); // closes "home_info"         //      },

  jg.add_key( "array_numbers" );
  jg.open_array();
  std::vector<int > vec_ints;
  vec_ints.clear();
  int some_num = 0;
  vec_ints.push_back( some_num+=1 );
  vec_ints.push_back( some_num+=1 );
  vec_ints.push_back( some_num+=1 );
  jg.add_value( vec_ints );
  jg.close_array();                                //      "array_numbers": [ 1, 2, 3 ]
  jg.close_object(); //closes "person"             //    }

  jg.close_object(); //closes schema               //  }


  cout<<"----Formatted content string START: "<<endl;
  cout<<jg.get_contents_string( true )<<endl;
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
      "type": "File",
      "popup": {
        "menuitem": [ {
	  "value": "New",
	  "onclick": "CreateNewDoc()"
	  "colors": [ 4578, 4577, 4576 ]
	},
	{
	  "value": "Open",
	  "onclick": "OpenDoc()"
	},
	{
	  "value": "Close",
	  "onclick": "CloseDoc()"
        } ]
      }
    }
  }
  */
  jg.clear_contents();

  jg.open_object(); //start schema        // {
  
  jg.open_object( "menu" );               //    "menu": {
  jg.add_pair("id","file");               //      "id": "file",
  jg.add_pair("type","File");             //      "type": "File",
  jg.open_object("popup");                //        "popup": {
  jg.add_key("menuitem");
  
  jg.open_array();

  jg.open_object();                        //       "menuitem": [ {
  jg.add_pair("value","New");              //	      "value": "New",
  jg.add_pair("onclick","CreateNewDoc()"); //	      "onclick": "CreateNewDoc()"
  std::vector<int> color_vals;
  color_vals.push_back( 4578 );
  color_vals.push_back( 4577 );
  color_vals.push_back( 4576 );
  jg.add_pair("colors",color_vals);        //         "colors": [ 4578, 4577, 4576 ]
  jg.close_object();                       //	    },

  jg.open_object();                        //       {
  jg.add_pair("value", "Open");            //	      "value": "Open",
  jg.add_pair("onclick","OpenDoc()");      //	      "onclick": "OpenDoc()"
  jg.close_object();                       //       },

  jg.open_object();                        //       {
  jg.add_pair("value","Close");            //	      "value": "Close",
  jg.add_pair("onclick","CloseDoc()");     //	      "onclick": "CloseDoc()"
  jg.close_object(); 
  jg.close_array();                        //       } ]

  jg.close_object();                       //     }
  jg.close_object();                       //   }
  jg.close_object();                       // }


  cout<<"----Formatted content string START: "<<endl;
  cout<<jg.get_contents_string( true )<<endl;
  cout<<"----Formatted content string STOP: "<<endl;
  cout<<"----Organisation string START: "<<endl;
  cout<<jg.get_organisation_string()<<endl;
  cout<<"----Organisation string START: "<<endl;
  jg.print();




  //TEST 3
  // Example from:
  /*
  {
    "glossary": {
      "title": "example glossary",
      "GlossDiv": {
	"title": "S",
	"GlossList": {
	  "GlossEntry": {
	    "ID": "SGML",
	    "SortAs": "SGML",
	    "GlossTerm": "Standard Generalized Markup Language",
	    "Acronym": "SGML",
	    "Abbrev": "ISO 8879:1986",
	    "GlossDef": {
	      "para": "A meta-markup language... .",
	      "GlossSeeAlso": ["GML", "XML"] 
	    },
	    "GlossSee": "markup"
          }        
        }        
      }        
    }         
  }         
  */

  jg.clear_contents(); //reset for test

  jg.open_object();                                                 //  {

  jg.open_object( "glossary" );                                     //    "glossary": {
  jg.add_pair("title","example glossary");                          //      "title": "example glossary",

  jg.open_object( "GlossDiv" );                                     //	    "GlossDiv": {
  jg.add_pair("title","S");                                         //	      "title": "S",

  jg.open_object( "GlossList" );                                    // 	      "GlossList": {

  jg.open_object( "GlossEntry" );                                   //	        "GlossEntry": {
  jg.add_pair("ID","SGML");                                         //	          "ID": "SGML",
  jg.add_pair("SortAs","SGML");                                     //	          "SortAs": "SGML",
  jg.add_pair("GlossTerm","Standard Generalized Markup Language");  //	          "GlossTerm": "Standard Generalized Markup Language",
  jg.add_pair("Acronym","SGML");                                    //	          "Acronym": "SGML",
  jg.add_pair("Abbrec","ISO 8879:1986");                            //	          "Abbrev": "ISO 8879:1986",

  jg.open_object( "GlossDeff" );                                    //	          "GlossDef": {
  jg.add_pair("para","A meta-markup language... .");                //	            "para": "A meta-markup language... .",
  std::vector<std::string> otherFormats;
  otherFormats.push_back("GML");
  otherFormats.push_back("XML");
  jg.add_pair("GlossSeeAlso", otherFormats );                       //	            "GlossSeeAlso": ["GML", "XML"]
  jg.close_object();  // closes "GlossDeff"                         //            },

  jg.add_pair("GlossSee", "markup" );                               //	          "GlossSee": "markup"
  jg.close_object();  // closes "GlossEntry"                        //          }    
  jg.close_object();  // closes "GlossList"                         //        }
  jg.close_object();  // closes "GlossDiv"                          //      }
  jg.close_object();  // closes "glossary"                          //    }
  jg.close_object();  // closes entire schema                       //  }


  cout<<"----Formatted content string START: "<<endl;
  cout<<jg.get_contents_string( true )<<endl;
  cout<<"----Formatted content string STOP: "<<endl;
  cout<<"----Organisation string START: "<<endl;
  cout<<jg.get_organisation_string()<<endl;
  cout<<"----Organisation string START: "<<endl;
  jg.print();



  cout<<"** CPPJSONGENERATOR - TEST - STOP"<<endl;

  return 0;
}
