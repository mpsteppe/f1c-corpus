int __thiscall sub_42F6D0(int this, int a2, int a3)
{
  double v4; // st7
  int v6; // [esp+0h] [ebp-20h] BYREF
  _BYTE v7[4]; // [esp+4h] [ebp-1Ch] BYREF
  _BYTE v8[4]; // [esp+8h] [ebp-18h] BYREF
  _BYTE v9[4]; // [esp+Ch] [ebp-14h] BYREF
  _BYTE v10[4]; // [esp+10h] [ebp-10h] BYREF
  _BYTE v11[12]; // [esp+14h] [ebp-Ch] BYREF

  v6 = a3;
  sub_4092E0();
  if ( *(_DWORD *)(this + 16) )
  {
    sub_5DA610(&v6, v7, v8, v9, v10, v11);
    v4 = sub_403040(&flt_91BCA0, (float *)&v6);
  }
  else
  {
    v4 = 0.0;
  }
  *(float *)(this + 104) = v4;
  sub_556230(&unk_FADD40, this, a2, v6);
  return sub_5570C0(this);
}
