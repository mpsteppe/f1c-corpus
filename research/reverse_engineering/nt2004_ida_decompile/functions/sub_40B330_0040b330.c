void __thiscall sub_40B330(int this, int a2, int a3, char a4)
{
  const char *v5; // eax
  const char *v6; // eax
  int v7; // [esp+0h] [ebp-44h]
  float v8; // [esp+4h] [ebp-40h]
  int v9[3]; // [esp+14h] [ebp-30h] BYREF
  int v10[3]; // [esp+20h] [ebp-24h] BYREF
  int v11[3]; // [esp+2Ch] [ebp-18h] BYREF
  int v12[3]; // [esp+38h] [ebp-Ch] BYREF

  if ( a2 && *(_DWORD *)(this + 40) )
  {
    if ( (_BYTE)a3 )
    {
      v5 = (const char *)sub_459B80(a2);
      if ( _strcmpi(v5, aSwingman) )
        sub_459B30(a2);
      if ( *(_DWORD *)(this + 20) )
        sub_459BC0(v9, 0);
      else
        memset(v9, 0, sizeof(v9));
    }
    if ( *(_BYTE *)(this + 36) )
    {
      sub_459B30(a2);
      *(_BYTE *)(this + 36) = 0;
    }
    v6 = (const char *)sub_459B80(a2);
    if ( _strcmpi(v6, aCockpit) )
      sub_50C600(v11, v12);
    else
      sub_50C6A0(v11, v12);
    v10[0] = *(_DWORD *)(dword_75AAC4 + 160);
    v10[1] = *(_DWORD *)(dword_75AAC4 + 164);
    v10[2] = *(_DWORD *)(dword_75AAC4 + 168);
    if ( sub_459B90(a2) == 1 )
      sub_409AD0(a2);
    v8 = sub_40BEC0(this);
    *(float *)&v7 = sub_40BEB0(this);
    sub_459B40((int)v11, (int)v12, (int)v10, v7, v8);
    if ( (unsigned __int8)sub_459C60(a2) )
      sub_409BB0((void *)this, a2);
    if ( a4 )
    {
      sub_40B4A0(a3);
      sub_40B9B0(a3);
      sub_40BAB0(a3, v9, v11);
      sub_40BB10(a3);
    }
  }
}
