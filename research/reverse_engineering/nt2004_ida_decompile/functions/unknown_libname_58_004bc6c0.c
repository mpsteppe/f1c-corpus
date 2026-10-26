// Microsoft VisualC 2-14/net runtime
void *unknown_libname_58()
{
  _DWORD *v0; // eax
  int v1; // ecx

  v0 = &unk_76627C;
  v1 = 14;
  do
  {
    *v0 = 0;
    v0[1] = -1;
    v0 += 2;
    --v1;
  }
  while ( v1 );
  dword_7662F0 = 0;
  dword_7662F4 = 0;
  dword_7662F8 = 0;
  dword_7662FC = 0;
  sub_4BD290(&unk_766238);
  return &unk_766238;
}
