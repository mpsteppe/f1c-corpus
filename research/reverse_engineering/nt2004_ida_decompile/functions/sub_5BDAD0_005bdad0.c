int __fastcall sub_5BDAD0(int a1, int a2)
{
  int v3; // eax
  _DWORD *v4; // eax
  int v6; // eax
  _DWORD v7[2]; // [esp+8h] [ebp-8h] BYREF

  v7[0] = a2;
  v3 = sub_5B9FF0();
  v4 = (_DWORD *)sub_5BE0C0(v3, v7);
  if ( v4 )
  {
    ++v4[1];
    return *v4;
  }
  else
  {
    v7[0] = sub_5BDBC0(a2);
    v7[1] = 1;
    v6 = sub_5B9FF0();
    sub_5BE020(v6, v7);
    return v7[0];
  }
}
