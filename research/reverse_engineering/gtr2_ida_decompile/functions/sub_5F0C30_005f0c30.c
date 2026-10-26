int __thiscall sub_5F0C30(void *this, char *Str, int nNumber, LONG a4, int a5, int a6, unsigned int a7, int **a8)
{
  char *v9; // eax
  char *v10; // eax
  int v11; // ecx
  char *v12; // esi
  int *v13; // esi
  void *v14; // eax
  char String[64]; // [esp+Ch] [ebp-4Ch] BYREF
  int v17; // [esp+54h] [ebp-4h]

  v9 = strrchr(Str, 92);
  if ( v9 )
    v10 = v9 + 1;
  else
    v10 = Str;
  v11 = 0;
  if ( *v10 != 46 )
  {
    v12 = (char *)(String - v10);
    do
    {
      ++v11;
      v10[(_DWORD)v12] = *v10;
      ++v10;
    }
    while ( v11 < 63 && *v10 != 46 );
  }
  String[v11] = 0;
  _strupr(String);
  v13 = (int *)sub_5F04C0(this, String);
  if ( !v13 )
  {
    v14 = operator new(0x18BCu);
    v17 = 0;
    if ( v14 )
      v13 = (int *)sub_5EEB40((int)v14);
    else
      v13 = 0;
    v17 = -1;
    if ( sub_5F0760((int)v13, Str, nNumber, a4, a5, a6, a7) )
    {
      if ( v13 )
      {
        sub_5DA420(v13);
        j__free(v13);
      }
      return -1;
    }
    sub_5FDFB0(v13, 1);
  }
  ++v13[1582];
  if ( a8 )
    *a8 = v13;
  return 0;
}
