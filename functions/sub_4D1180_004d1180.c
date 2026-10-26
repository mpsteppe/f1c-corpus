char __stdcall sub_4D1180(_DWORD *a1, float *a2, _DWORD *a3)
{
  if ( dword_7C56A4 == 7 && (dword_7C56A8 == 2 || dword_7C56A8 == 3 || dword_7C56A8 == 4) )
  {
    SingleFunctionDispatch_10e0((int)a1, a2, a3);
    return 1;
  }
  else
  {
    RenderCallWithGuard(a1, a2, a3);
    return 0;
  }
}
