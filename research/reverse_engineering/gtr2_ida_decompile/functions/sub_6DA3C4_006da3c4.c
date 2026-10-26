bool __thiscall sub_6DA3C4(unsigned __int16 *this)
{
  unsigned int v1; // edx
  unsigned int v2; // edi
  unsigned __int16 *v3; // eax
  int v4; // esi
  unsigned __int16 *v5; // eax
  int v6; // esi
  unsigned __int16 *v7; // eax
  int v8; // esi
  bool result; // al

  v1 = 0;
  v2 = 0;
  v3 = this + 70;
  v4 = 7;
  do
  {
    v2 += *v3;
    v3 += 2;
    --v4;
  }
  while ( v4 );
  v5 = this + 84;
  v6 = 121;
  do
  {
    v1 += *v5;
    v5 += 2;
    --v6;
  }
  while ( v6 );
  v7 = this + 326;
  v8 = 128;
  do
  {
    v2 += *v7;
    v7 += 2;
    --v8;
  }
  while ( v8 );
  result = v1 >> 2 >= v2;
  *((_BYTE *)this + 28) = result;
  return result;
}
