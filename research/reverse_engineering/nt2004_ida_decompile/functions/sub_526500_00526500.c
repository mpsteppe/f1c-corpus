int __fastcall sub_526500(int a1, int a2, int a3)
{
  int v3; // eax

  if ( !VFXGetTracking )
    return 4;
  v3 = VFXGetTracking(a1, a2, a3);
  if ( v3 == 1 )
    return 0;
  if ( v3 == 2 || v3 == 3 )
    return 7;
  return 6;
}
