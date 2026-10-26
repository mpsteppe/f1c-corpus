_DWORD *__thiscall sub_438C10(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // ecx
  _DWORD *v4; // edi
  int v5; // edx

  sub_4353F0(this + 123);
  sub_42E1C0(this + 1371);
  sub_56D3E0(this + 1387);
  sub_4363D0(this + 1550);
  sub_4363D0(this + 1575);
  memset(this, 0, 0x1F38u);
  v2 = this + 374;
  v3 = 4;
  do
  {
    *v2 = -1889785610;
    v2[1] = 1081507266;
    v4 = v2 + 2;
    v2[2] = *v2;
    v2[3] = v2[1];
    v2[4] = v2[2];
    v5 = v2[3];
    v2 += 281;
    --v3;
    v4[3] = v5;
  }
  while ( v3 );
  sub_43E230(this);
  return this;
}
