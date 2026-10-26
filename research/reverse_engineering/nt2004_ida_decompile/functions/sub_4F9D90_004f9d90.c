int __thiscall sub_4F9D90(_DWORD *this)
{
  int v2; // esi
  int result; // eax
  bool v4; // zf
  int v5; // ecx
  int v6; // edx
  const char *v7; // edx
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  _DWORD *v10; // eax
  int j; // [esp+10h] [ebp-10Ch]
  int v12; // [esp+14h] [ebp-108h]
  char ArgList[125]; // [esp+1Ch] [ebp-100h] BYREF
  __int16 v14; // [esp+99h] [ebp-83h]
  char i; // [esp+9Bh] [ebp-81h]
  char Buffer[128]; // [esp+9Ch] [ebp-80h] BYREF

  ArgList[0] = byte_629120;
  v2 = this[59];
  result = 0;
  memset(&ArgList[1], 0, 0x7Cu);
  v14 = 0;
  for ( i = 0; v2; result = sub_5BE8AE() )
  {
    v4 = *(_BYTE *)(v2 + 8) == 0;
    v2 = *(_DWORD *)(v2 + 4);
    if ( !v4 )
      sub_5BE8AE();
  }
  this[59] = 0;
  this[60] = 0;
  this[61] = 0;
  this[62] = 0;
  if ( dword_7DA9B8 )
  {
    result = sub_597540(dword_7DA9B8);
    v5 = 0;
    v12 = result;
    for ( j = 0; j < v12; ++j )
    {
      if ( sub_597590(v5) )
      {
        sub_59EA30(ArgList);
        v6 = sub_579060(ArgList, aCautionLight);
        if ( v6 )
        {
          v7 = (const char *)(strlen(aCautionLight) + v6);
          if ( v7 )
            sprintf(Buffer, "%s%s", aCautionGlow, v7);
          else
            sprintf(Buffer, &byte_629120);
          _strupr(Buffer);
          v8 = operator new(0xCu);
          if ( v8 )
          {
            v8[1] = 0;
            v8[2] = 0;
            v9 = v8;
          }
          else
          {
            v9 = 0;
          }
          sub_4F8C90(v9, (int)ArgList, (int)Buffer);
          if ( v9 )
          {
            v10 = operator new(0xCu);
            if ( v10 )
            {
              *v10 = v9;
              v10[1] = 0;
              *((_BYTE *)v10 + 8) = 1;
            }
            else
            {
              v10 = 0;
            }
            if ( this[59] )
            {
              *(_DWORD *)(this[60] + 4) = v10;
            }
            else
            {
              this[59] = v10;
              this[61] = v10;
            }
            this[60] = v10;
            ++this[62];
          }
        }
      }
      result = v12;
      v5 = j + 1;
    }
  }
  return result;
}
