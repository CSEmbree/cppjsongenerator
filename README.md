# CppJSONGenerator
*******************************************************************
README Content is broken up as follows:

1. PURPOSE
2. INSTALL
3. BASIC USE
4. DEPENDANCIES
5. EXAMPLE
6. REFERENCES
7. TODO


*******************************************************************
## 1. PURPOSE
*******************************************************************
The purpose of _cppjsongenerator_ is to generate SMALL amounts of
JSON output using a C++ object. 

For the duration of this document, the variable `$CPPJSONGENERATOR`
refers to the installation/download location of the cppjsongenerator
git repository on your machine.

Questions, comments, or bugs should be reported to:
`cse@cameronembree.com`


*******************************************************************
## 2. INSTALL
*******************************************************************
Inlcude files from the _$CPPJSONGENERATOR/src_ to your source code 
directory. Create an instance of the cppjsongenerator object and 
use it as instructed in the `3. BASIC USE` section.


*******************************************************************
## 3. BASIC USE
*******************************************************************
After including the `cppjsongenerator` class in your build path,
create and instance of it and use it as you would expect. For 
example, the following code:
```c
  string fileName = "json_example.txt";
  json_generator jg( fileName );

  jg.open_object();                          //{                                                                                 

  jg.add_pair("title","Example Schema");     //  "title": "Example Schema",                                                      
  jg.add_pair("type","object");              //  "type": "object",                                                               

  jg.open_object("properties");              //  "properties": {                                                                 

  jg.open_object("firstName");               //    "firstName": {                                                                
  jg.add_pair("type","string");              //      "type": "string"                                                            
  jg.close_object();                         //    },                                                                            

  jg.open_object("lastName");                //    "lastName": {                                                                 
  jg.add_pair("type","string");              //      "type": "string"                                                            
  jg.close_object();                         //    }                                                                             

  jg.open_object("age");                     //    "age": {                                                                      
  jg.add_pair("description","Age in years"); //      "description": "Age in years",                                              
  jg.add_pair("type","integer");             //      "type": "integer",                                                          
  jg.add_pair("minimum",0);                  //      "minimum": 0                                                                
  jg.close_object();                         //    }                                                                             
  jg.close_object();                         //  },                                                                              

  // vectors are used to represent arrays
  std::vector<string > requiredFields;
  requiredFields.push_back("firstName");
  requiredFields.push_back("lastName");
  jg.add_pair("required", requiredFields);   //  "required": ["firstName", "lastName"]                                           

  jg.close_object();                         //} 
```

generates the following JSON output as a file called _example.txt_

```json
{
"title": "Example Schema",
"type": "object",
"properties": {
"firstName": {
"type": "string"
},
"lastName": {
"type": "string"
},
"age": {
"description": "Age in years",
"type": "integer",
"minimum": 0
}
},
"required": ["firstName", "lastName"]
}
```


Additonal examples of using _cppjsongenerator_ can be found in the
`5. EXAMPLE` section


*******************************************************************
## 4. DEPENDANCIES
*******************************************************************
This library only uses standard c++ libraries.


*******************************************************************
## 5. EXAMPLE
*******************************************************************
Multple examples of how to use this library can be found in
```bash
$cppjsongenerator/tests
```


*******************************************************************
## 6. REFERENCES
*******************************************************************
JSON format generation rules implimented by the design here:

**http://www.w3schools.com/json/json_syntax.asp**

The example in the `3. Basic Use` section was borrowed from:

**http://json-schema.org/examples.html**

JSON generated by _cppjsongenerator_ were validated with:

**http://jsonlint.com/**



*******************************************************************
## 7. TODO
*******************************************************************
- [X] Finish basic design
- [ ] Choose testing environment for _cppjsongenerator_. Use GoogleTest?
- [ ] Create Unit tests for cppjsongenerator.cpp
