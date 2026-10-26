int *__thiscall sub_4090C0(_DWORD *this)
{
  int v2; // eax
  int *result; // eax
  int v4; // ecx
  bool v5; // zf
  int i; // edi
  const char *v7; // eax
  int v8; // [esp+Ch] [ebp-204h] BYREF
  char Buffer[509]; // [esp+10h] [ebp-200h] BYREF
  __int16 v10; // [esp+20Dh] [ebp-3h]
  char v11; // [esp+20Fh] [ebp-1h]

  v2 = sub_5971C0(aMainview);
  this[10] = v2;
  if ( v2 )
    sub_593430(1);
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x1FCu);
  v10 = 0;
  v11 = 0;
  sub_40BB40(Buffer, 512);
  sub_40A8A0(Buffer);
  sub_40BB80(Buffer, 512);
  sub_40A8A0(Buffer);
  sub_40A150(this);
  result = (int *)sub_595470(32, 1);
  this[12] = 0;
  *((_BYTE *)this + 52) = 0;
  this[15] = 0;
  this[14] = 0;
  this[16] = 0;
  *((_BYTE *)this + 36) = 1;
  *((_BYTE *)this + 73) = 0;
  byte_762AF8 = 0;
  v4 = this[10];
  this[19] = 0;
  this[20] = 0;
  this[21] = 0;
  this[22] = 0;
  this[23] = 0;
  this[24] = 0;
  if ( v4 )
  {
    v8 = 1112014848;
    sub_593EF0(0, &v8);
    result = (int *)*this;
    v5 = *this == 0;
    this[2] = *this;
    if ( !v5 )
    {
      for ( i = *result; *result; i = *result )
      {
        v7 = (const char *)sub_459BA0(i);
        if ( !_strcmpi(v7, aDrivable) )
          sub_459CC0(0, &v8);
        result = (int *)this[2];
        if ( !result )
          break;
        result = (int *)result[1];
        this[2] = result;
        if ( !result )
          break;
      }
    }
  }
  return result;
}
