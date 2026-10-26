int __stdcall sub_4CEEF0(int a1, int a2)
{
  const char *v2; // ecx
  const char *v3; // eax

  v2 = (const char *)dword_5EC420;
  if ( !dword_5EC420 )
    v2 = byte_5EA438;
  v3 = (const char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v3 = byte_5EA438;
  return sub_58815F(a1, "%s%sterrain.ini", v3, v2);
}
