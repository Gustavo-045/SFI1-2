static void changeVar(uint32_t *pdata, uint32_t *pdata2)
{
    uint32_t temp = *pdata;
    *pdata = *pdata2;
    *pdata2 = temp;
}

static void printVar(uint32_t value)
{
    Serial.print("var content: ");
    Serial.print(value);
    Serial.print('\n');
}

void task1()
{
    enum class Task1States    {
        INIT,
        WAIT_DATA
    };
    static Task1States task1State = Task1States::INIT;

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        task1State = Task1States::WAIT_DATA;
        break;
    }

    case Task1States::WAIT_DATA:
    {
        // evento 1:        // Ha llegado al menos un dato por el puerto serial?        
     if (Serial.available() > 0)
        {
            Serial.read();
            uint32_t var = 0;
            uint32_t var2 = 1;
            uint32_t *pvar = &var;
            uint32_t *pvar2 = &var2;
            
            printVar(*pvar);
            printVar(*pvar2);
            changeVar(pvar, pvar2);
            printVar(var);
            printVar(var2);
        }
        break;
    }

    default:
    {
        break;
    }
    }
}

void setup()
{
    task1();
}

void loop()
{
    task1();
}
