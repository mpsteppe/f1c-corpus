__int16 __thiscall sub_4CD6E0(char *this, char *Destination, int a3)
{
  __int16 result; // ax
  char Buffer[32]; // [esp+Ch] [ebp-20h] BYREF

  sub_4CD640(this, Buffer, 32);
  sub_4CD5B0(this, Destination, a3 - strlen(Buffer));
  strcat(Destination, Buffer);
  result = *(_WORD *)word_5FB9F4;
  *(_WORD *)&Destination[strlen(Destination)] = *(_WORD *)word_5FB9F4;
  return result;
}
