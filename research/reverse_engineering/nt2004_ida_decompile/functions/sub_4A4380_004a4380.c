int __thiscall sub_4A4380(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // ecx
  int v7; // ebx
  int v8; // ebp
  int v9; // edi
  int v10; // eax
  int v12; // [esp+10h] [ebp-4h]

  v6 = dword_7656E0;
  v7 = this[1];
  v8 = this[4];
  v9 = this[3];
  v12 = this[2];
  if ( dword_7656E0 )
  {
    if ( !this[67] )
    {
      this[67] = sub_597290(dword_7656E0);
      v6 = dword_7656E0;
    }
    if ( v6 && this[67] )
    {
      sub_5278E0(&unk_7DA938);
      sub_598430(dword_7DA988);
      sub_527910(&unk_7DA938);
      v10 = sub_4AB570(&unk_765B00);
      sub_593F30(v10);
      sub_593B30(0.0, 0.0, 1.0, 1.0, 0);
      sub_5932C0(14);
    }
  }
  *a2 = v7;
  *a4 = v9;
  *a3 = v12;
  *a5 = v8;
  return 0;
}
