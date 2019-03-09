#include"util.h"


bool check(const std::string& temp1, const std::string& temp2){
  return (temp1 == temp2);
}

std::string cal(std::string date, std::vector<std::string> product, std::vector<std::string> consumer){
  std::vector<std::string>::iterator product_ip{};
  std::vector<std::string>::iterator consumer_ip{};
  std::string str{};

  std::sort(product.begin(), product.end());
  product_ip = std::unique(product.begin(), product.end());
  product.resize(std::distance(product.begin(), product_ip));

  std::sort(consumer.begin(), consumer.end());
  consumer_ip = std::unique(consumer.begin(), consumer.end());
  consumer.resize(std::distance(consumer.begin(), consumer_ip));

  // for showing the consumer and product id in a date use the following code !!!
  /*
  for(auto i:consumer)
    std::cout << i << std::endl;
  for(auto i:product)
    std::cout << i << std::endl;
  */
  
  str = "[" + date + "]" + " " + std::to_string(product.size()) + " " + std::to_string(consumer.size()) + '\n';
  std::cout << str;
  
  return str;
}

void Create_Text(std::ifstream& inFile, std::ofstream& outFile){
  char ch{};
  std::string date {};
  std::string time{};
  std::string product_id{};
  std::string consumer_id{};
  std::vector<std::string> vec_product_id {};
  std::vector<std::string> vec_consumer_id{};
  std::string temp_date{};
  std::vector<std::string> result {};
  
  if(!inFile)
    std::cout << "ERROR IN READING FILE" << std::endl;
  
  inFile >> ch >> date >> time >> product_id >> consumer_id;
  
  temp_date = date;
  vec_product_id.push_back(product_id);
  vec_consumer_id.push_back(consumer_id);
  
  do{
    inFile >> ch >> date >> time >> product_id >> consumer_id;
    
    if(check(date, temp_date)){
      vec_product_id.push_back(product_id);
      vec_consumer_id.push_back(consumer_id);
    }
    else if(!check(date, temp_date)){
      result.push_back(cal(temp_date, vec_product_id, vec_consumer_id));
      temp_date = date;
      vec_product_id.clear();
      vec_consumer_id.clear();
      vec_product_id.push_back(product_id);
      vec_consumer_id.push_back(consumer_id);
    }
  }while(!inFile.eof());
  
  result.push_back(cal(temp_date, vec_product_id, vec_consumer_id));
  
  for(auto i:result)
    outFile << i;
   
  inFile.close();
  outFile.close();
}
