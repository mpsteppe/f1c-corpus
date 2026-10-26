int __thiscall sub_4E4840(CHAR ****this)
{
  int v2; // eax
  int v3; // esi
  int v4; // ebp
  int v5; // eax
  const char *v6; // ebx
  int v7; // esi
  CHAR *v8; // eax
  int v10; // [esp+10h] [ebp-4h]

  v2 = sub_57AE50(aRaceorder);
  v3 = v2;
  v10 = v2;
  if ( !v2 )
    return -1;
  v4 = (int)this[7742] + 1;
  if ( v4 >= sub_57A6E0(v2) )
    return -1;
  while ( 1 )
  {
    v5 = sub_57A700(v4);
    if ( v5 )
      break;
LABEL_8:
    if ( ++v4 >= sub_57A6E0(v3) )
      return -1;
  }
  v6 = (const char *)sub_57A6C0(v5);
  v7 = 0;
  if ( sub_4B15C0(this) <= 0 )
  {
LABEL_7:
    v3 = v10;
    goto LABEL_8;
  }
  while ( 1 )
  {
    v8 = sub_4E4800(this, v7);
    if ( !_strcmpi(v6, v8) )
      return v4;
    if ( ++v7 >= sub_4B15C0(this) )
      goto LABEL_7;
  }
}
