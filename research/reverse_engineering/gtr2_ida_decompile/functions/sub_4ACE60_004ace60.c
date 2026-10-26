char __thiscall sub_4ACE60(_DWORD **this)
{
  const char *v2; // eax
  const char *v3; // esi
  char *v4; // eax
  const CHAR *v5; // eax
  const char *v6; // eax
  const char *v7; // ecx
  const char *v8; // eax
  int v9; // esi
  int v10; // edi
  char String2[253]; // [esp+18h] [ebp-610h] BYREF
  __int16 v13; // [esp+115h] [ebp-513h]
  char v14; // [esp+117h] [ebp-511h]
  _BYTE v15[253]; // [esp+118h] [ebp-510h] BYREF
  __int16 v16; // [esp+215h] [ebp-413h]
  char v17; // [esp+217h] [ebp-411h]
  char v18[1028]; // [esp+218h] [ebp-410h] BYREF
  int v19; // [esp+624h] [ebp-4h]

  sub_4D2690();
  v2 = (const char *)sub_499890();
  v3 = v2;
  if ( !v2 || !strlen(v2) )
    return 0;
  strcpy(v18, v3);
  v4 = &v18[strlen(v18)];
  if ( v4 > v18 )
  {
    while ( *v4 != 46 )
    {
      if ( --v4 <= v18 )
        goto LABEL_8;
    }
    *v4 = 0;
  }
LABEL_8:
  sub_615860(v18);
  v5 = dword_B7235C;
  if ( !dword_B7235C )
    v5 = WindowName;
  sub_615860(v5);
  v19 = 0;
  sub_514EC0(v3, 0);
  if ( sub_48BF60() )
  {
    memset(String2, 0, sizeof(String2));
    v13 = 0;
    v14 = 0;
    memset(v15, 0, sizeof(v15));
    v16 = 0;
    v17 = 0;
    v6 = *(const char **)dword_91CA70;
    if ( !*(_DWORD *)dword_91CA70 )
      v6 = WindowName;
    if ( (int)sub_632041(String2, 255, "%s%s", v6, WindowName) >= 0 )
    {
      sub_616C30(String2);
      v7 = dword_B7235C;
      if ( !dword_B7235C )
        v7 = WindowName;
      v8 = *(const char **)dword_91CA70;
      if ( !*(_DWORD *)dword_91CA70 )
        v8 = WindowName;
      if ( (int)sub_632041(v15, 255, "%s%s", v8, v7) >= 0 && (unsigned __int8)sub_616F90(v15, 0) != 1 )
      {
        sub_615860(WindowName);
        sub_616F90(String2, 0);
      }
    }
  }
  v9 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 17);
  v10 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 1);
  if ( v9 )
    sub_49DCF0();
  if ( v10 )
    sub_4993D0();
  return 1;
}
