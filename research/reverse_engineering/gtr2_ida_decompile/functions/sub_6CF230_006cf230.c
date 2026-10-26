int __stdcall sub_6CF230(_DWORD *a1)
{
  int v1; // edi
  int result; // eax

  v1 = a1[108];
  result = *(_DWORD *)(v1 + 16);
  if ( result )
  {
    result = a1[20];
    if ( result )
    {
      result = sub_6CEB60((int)a1);
      if ( result )
      {
        *(_DWORD *)(v1 + 12) = sub_6CEC90;
        a1[40] = 0;
        return result;
      }
    }
    *(_DWORD *)(v1 + 12) = sub_6CE9E0;
  }
  a1[40] = 0;
  return result;
}
