int __stdcall sub_549110(_DWORD *a1)
{
  if ( a1[17] )
    sub_549110(a1[17]);
  if ( a1[16] && a1[19] )
    sub_549110(a1[19]);
  if ( SceneGraph(a1) )
    return -1;
  TwoFunctionCallChain(a1);
  FreeWrapper_7bcf(a1);
  return 0;
}

