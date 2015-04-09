#python
def eh_vogal(letra):
    vogais = "aeiouAEIOU"
    for x in vogais:
        if letra == x:
            return True
    return False

#c++
bool eh_vogal(char letra){
    string vogais = "aeiouAEIOU";
    for (char x : vogais)
        if(x == letra)
            return true;
    return false;
}
#c
int eh_vogal(char letra){
    char *vogais = "aeiouAEIOU";
    int i;
    for (i = 0; i < strlen(vogais); i++)
        if(letra == vogais[i])
            return 1;
    return 0;
}
