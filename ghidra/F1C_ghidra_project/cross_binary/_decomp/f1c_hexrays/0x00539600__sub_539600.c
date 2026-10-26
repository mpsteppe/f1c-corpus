// f1c  0x00539600  size=112
BOOL __thiscall sub_539600(unsigned __int16 *this)
{
  unsigned int v1; // ebx
  unsigned int v2; // esi
  unsigned __int16 *v3; // eax
  int v4; // edx
  unsigned __int16 v5; // di
  unsigned __int16 *v6; // eax
  int v7; // edx
  unsigned __int16 v8; // bp
  unsigned __int16 *v9; // edx
  int v10; // eax
  unsigned __int16 v11; // di
  unsigned int v12; // ebx
  BOOL result; // eax

  v1 = 0;
  v2 = 0;
  v3 = this + 69;
  v4 = 7;
  do
  {
    v5 = *v3;
    v3 += 2;
    v2 += v5;
    --v4;
  }
  while ( v4 );
  v6 = this + 83;
  v7 = 121;
  do
  {
    v8 = *v6;
    v6 += 2;
    v1 += v8;
    --v7;
  }
  while ( v7 );
  v9 = this + 325;
  v10 = 128;
  do
  {
    v11 = *v9;
    v9 += 2;
    v2 += v11;
    --v10;
  }
  while ( v10 );
  v12 = v1 >> 2;
  result = v2 <= v12;
  *((_BYTE *)this + 28) = v2 <= v12;
  return result;
}
