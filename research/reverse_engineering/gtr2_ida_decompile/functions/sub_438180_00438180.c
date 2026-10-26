int __thiscall sub_438180(char **this, int a2)
{
  int v2; // eax
  int v3; // esi
  int result; // eax
  int v6; // ebp
  char *v7; // eax
  char **v8; // esi
  char *v9; // eax
  char *v10; // ecx
  const CHAR *v11; // esi
  const CHAR *v12; // eax
  int v13; // [esp+18h] [ebp-110h]
  int v14; // [esp+1Ch] [ebp-10Ch]
  int v15; // [esp+20h] [ebp-108h] BYREF
  char v16[8]; // [esp+94h] [ebp-94h] BYREF

  v2 = dword_757C10;
  v3 = a2;
  if ( a2 < 0 || a2 >= dword_757C10 )
    v3 = 0;
  else
    v2 = a2 + 1;
  v15 = v2;
  result = sub_436290();
  v14 = v3;
  if ( v3 < v13 )
  {
    while ( 1 )
    {
      v6 = *(&dword_91E088 + v14);
      if ( !*(_DWORD *)(v6 + 14820) )
        break;
      sub_630FE0(v6 + 22212, &v15, 255);
      *(_BYTE *)(v6 + 22467) = 0;
LABEL_25:
      result = ++v14;
      if ( v14 >= v13 )
        return result;
    }
    sub_436130();
    v7 = *this;
    if ( !*this )
      v7 = (char *)WindowName;
    sub_617680(v7);
    if ( byte_FADD28 )
    {
      v8 = this + 4;
      sub_615860(WindowName);
      sub_54BAB0(&unk_BE27B0, &byte_B6F530);
    }
    else
    {
      v8 = this + 4;
      if ( !sub_437AD0() )
      {
        sub_615860(v16);
        v9 = *this;
        if ( !*this )
          v9 = (char *)WindowName;
        v10 = *v8;
        if ( !*v8 )
          v10 = (char *)WindowName;
        if ( (unsigned __int8)sub_617D00(v10, v9) )
          goto LABEL_20;
        sub_437C50();
      }
      sub_615860(WindowName);
    }
LABEL_20:
    v11 = *v8;
    if ( !v11 )
      v11 = WindowName;
    sub_615860(v11);
    v12 = *this;
    if ( !*this )
      v12 = WindowName;
    sub_630FE0(v6 + 22212, v12, 255);
    *(_BYTE *)(v6 + 22467) = 0;
    sub_4363E0();
    goto LABEL_25;
  }
  return result;
}
