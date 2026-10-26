bool __thiscall sub_62DD40(int this)
{
  unsigned int v1; // esi
  unsigned int v2; // eax
  unsigned __int16 *v3; // edx
  int v4; // edi
  unsigned __int16 *v5; // edx
  int v6; // edi
  bool result; // al

  v1 = 0;
  v2 = *(unsigned __int16 *)(this + 138)
     + *(unsigned __int16 *)(this + 142)
     + *(unsigned __int16 *)(this + 146)
     + *(unsigned __int16 *)(this + 150)
     + *(unsigned __int16 *)(this + 154)
     + *(unsigned __int16 *)(this + 158)
     + *(unsigned __int16 *)(this + 162);
  v3 = (unsigned __int16 *)(this + 166);
  v4 = 121;
  do
  {
    v1 += *v3;
    v3 += 2;
    --v4;
  }
  while ( v4 );
  v5 = (unsigned __int16 *)(this + 650);
  v6 = 128;
  do
  {
    v2 += *v5;
    v5 += 2;
    --v6;
  }
  while ( v6 );
  result = v1 >> 2 >= v2;
  *(_BYTE *)(this + 28) = result;
  return result;
}
