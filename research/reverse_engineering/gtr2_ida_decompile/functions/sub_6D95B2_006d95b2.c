int __usercall sub_6D95B2@<eax>(int result@<eax>)
{
  _WORD *v1; // ecx
  int v2; // edx
  _WORD *v3; // ecx
  int v4; // edx
  _WORD *v5; // ecx
  int v6; // edx

  v1 = (_WORD *)(result + 140);
  v2 = 286;
  do
  {
    *v1 = 0;
    v1 += 2;
    --v2;
  }
  while ( v2 );
  v3 = (_WORD *)(result + 2432);
  v4 = 30;
  do
  {
    *v3 = 0;
    v3 += 2;
    --v4;
  }
  while ( v4 );
  v5 = (_WORD *)(result + 2676);
  v6 = 19;
  do
  {
    *v5 = 0;
    v5 += 2;
    --v6;
  }
  while ( v6 );
  *(_DWORD *)(result + 5796) = 0;
  *(_DWORD *)(result + 5792) = 0;
  *(_DWORD *)(result + 5800) = 0;
  *(_DWORD *)(result + 5784) = 0;
  *(_WORD *)(result + 1164) = 1;
  return result;
}
