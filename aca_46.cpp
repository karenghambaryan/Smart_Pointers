 //Ստեղծել car engine և driver class-ները և ստեղծել նրանց հարաբերությունները
#include <iostream>
#include <string>
class Engine
{
    private:
    std::string m_type;
    double m_Displacement;
    int m_Horsepower;
    public:
    Engine(const std::string& type, double Displacement, int Horsepower)
    {
        m_type = type;
        m_Displacement = Displacement;
        m_Horsepower = Horsepower;
    }
    Engine()
    {
        m_type = "Unknown";
        m_Displacement = 0;
        m_Horsepower = 0;
    }
    ~Engine()
    {
        std::cout << "I'm destructor of Engine" << std::endl;
    }
    std::string GetType()
    {
        return m_type;
    }


};
class Driver
{
    private:
    std::string m_name;
    int m_age;
    std::string m_LicenseType;
    public:
    Driver(const std::string& name, const std::string& LicenseType, int age)
    {
        m_name = name;
        m_LicenseType = LicenseType;
        m_age = age;
    }
    Driver()
    {
        m_name = "Unknown";
        m_age = 0;
        m_LicenseType = "Unknown";
    }
    ~Driver()
    {
        std::cout << "I'm destructor of Driver" << std::endl;
    }
    std::string GetLicense()
    {
        return m_LicenseType;
    }
    
};
class Car
{
    private:
    std::string m_name;
    std::string m_make;
    std::string m_color;
    int m_year;
    Engine m_engine;
    std::string m_valid;
    public:
    Car(const std::string& name, const std::string& make, const std::string& color, int year,const std::string& valid)
    {
        m_name = name;
        m_make = make;
        m_color = color;
        m_year = year;
        m_valid = valid;
    }
    Car()
    {
        m_make = "Unknown";
        m_name = "Unknown";
        m_color = "Unkwnown";
        m_year = 0;

    }
    ~Car()
    {
        std::cout << "I'm destructor of Car" << std::endl;
    }
    bool CanBe(Engine &e1)
    {
        if(e1.GetType() == "Disel" || e1.GetType() == "Gasoline" || e1.GetType() == "Hybrid")
        {
            return true;
        }
        return false;
    }
    bool CanDrive(std::string k)
    {
        if(m_valid ==k)
        {
            return true;
        }
        return false;
    }
};



int main()
{
    Car c1("Bmw", "E60","white",2010,"B");
    Driver d1("Arman","B",19);
    Driver d2("Aram","D",17);
    Engine e1("Disel", 2.4, 200);
    Engine e2("Electric",1.8,150);
    if(c1.CanBe(e2))
    {
        std::cout << "No problem" << std::endl;
    }
    else
    {
        std::cout << "Its Big problem" << std::endl; 
    }
    if(c1.CanBe(e1))
    {
        std::cout << "No problem" << std::endl;
    }
    else
    {
        std::cout << "Its Big problem" << std::endl; 
    }
    if(c1.CanDrive(d1.GetLicense()))
    {
        std::cout << "You can drive" << std::endl;
    }
    else
    {
        std::cout << "You can't drive" << std::endl;
    }
    if(c1.CanDrive(d2.GetLicense()))
    {
        std::cout << "You can drive" << std::endl;
    }
    else
    {
        std::cout << "You can't drive" << std::endl;
    }
    return 0;
}
