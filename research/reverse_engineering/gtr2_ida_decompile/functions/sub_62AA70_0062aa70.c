int __usercall sub_62AA70@<eax>(_DWORD *a1@<eax>)
{
  int v2; // edi
  int v3; // edi
  int v4; // edi
  int v5; // eax

  v2 = sub_62A360(a1);
  v3 = (sub_62A360(a1) << 8) + v2;
  v4 = (sub_62A360(a1) << 16) + v3;
  v5 = sub_62A360(a1);
  if ( v5 == -1 )
    a1[14] = -3;
  return v4 + (v5 << 24);
}
