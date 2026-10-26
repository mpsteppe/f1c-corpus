int __usercall sub_59A948@<eax>(_DWORD *a1@<ecx>, int a2@<ebp>)
{
  _DWORD *v3; // ecx

  v3 = a1 + 8;
  if ( v3 )
    LocaleRefcountAcquireUnderLock(v3);
  a1[2] = 0;
  a1[3] = 513;
  a1[4] = 6;
  a1[5] = 0;
  a1[6] = 0;
  a1[7] = 0;
  return sub_59A5FE(a2, 0, 0);
}

