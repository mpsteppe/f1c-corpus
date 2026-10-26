// positive sp value has been detected, the output may be wrong!
char __thiscall sub_616F97(_DWORD *this, int a2, int a3)
{
  char v4; // bl
  _DWORD v6[25]; // [esp-8h] [ebp-68h] BYREF
  int v7; // [esp+5Ch] [ebp-4h]

  v6[23] = NtCurrentTeb()->NtTib.ExceptionList;
  v4 = 0;
  sub_613B30(v6);
  v7 = 0;
  sub_614460(v6, a2, 0);
  if ( v6[1] )
  {
    sub_616A70(this, (int)v6);
    v4 = sub_616E80(this, v6, a3);
    sub_613C30((int)v6);
  }
  v7 = -1;
  sub_614140();
  return v4;
}
