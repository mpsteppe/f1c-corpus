// positive sp value has been detected, the output may be wrong!
char __thiscall sub_599560(_DWORD *this, int a2, char a3)
{
  _BYTE *v4; // ecx
  char v5; // al
  unsigned int v7; // eax
  int v8; // [esp-4h] [ebp-Ch]
  unsigned int retaddr; // [esp+8h] [ebp+0h]

  if ( retaddr > 0xFFFFFFFD )
    sub_59AD49(v8);
  v4 = (_BYTE *)this[1];
  if ( v4 )
  {
    v5 = *(v4 - 1);
    if ( v5 )
    {
      if ( v5 != -1 )
      {
        if ( !retaddr )
        {
          *(v4 - 1) = v5 - 1;
          sub_5993AF(this, 0);
          return 0;
        }
        goto LABEL_19;
      }
    }
  }
  if ( !retaddr )
  {
    if ( a3 )
    {
      sub_5993AF(this, 1);
    }
    else if ( v4 )
    {
      this[2] = 0;
      *v4 = 0;
    }
    return 0;
  }
  if ( a3 )
  {
    v7 = this[3];
    if ( v7 <= 0x1F && v7 >= retaddr )
      return 1;
    sub_5993AF(this, 1);
    goto LABEL_19;
  }
  if ( this[3] < retaddr )
LABEL_19:
    sub_59964A(retaddr);
  return 1;
}
