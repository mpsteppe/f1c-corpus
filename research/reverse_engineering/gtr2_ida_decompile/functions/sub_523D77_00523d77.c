// positive sp value has been detected, the output may be wrong!
char __thiscall sub_523D77(_DWORD *this, int a2, char *a3)
{
  int i; // esi
  int v6; // edi
  unsigned __int8 v7; // [esp-7h] [ebp-90Bh] BYREF
  char v8; // [esp-6h] [ebp-90Ah] BYREF
  char v9; // [esp-5h] [ebp-909h] BYREF
  int v10; // [esp-4h] [ebp-908h] BYREF
  int v11; // [esp+0h] [ebp-904h] BYREF
  int v12; // [esp+4h] [ebp-900h] BYREF
  int v13; // [esp+8h] [ebp-8FCh] BYREF
  void *v14; // [esp+Ch] [ebp-8F8h]
  int v15; // [esp+10h] [ebp-8F4h]
  void *Block; // [esp+14h] [ebp-8F0h] BYREF
  int v17; // [esp+18h] [ebp-8ECh] BYREF
  _BYTE v18[4]; // [esp+1Ch] [ebp-8E8h] BYREF
  int v19; // [esp+20h] [ebp-8E4h] BYREF
  _BYTE v20[8]; // [esp+7Ch] [ebp-888h] BYREF
  _BYTE v21[8]; // [esp+17Ch] [ebp-788h] BYREF
  _DWORD v22[428]; // [esp+250h] [ebp-6B4h] BYREF
  int v23; // [esp+900h] [ebp-4h]

  v22[426] = NtCurrentTeb()->NtTib.ExceptionList;
  sub_613B30(&v19);
  v23 = 0;
  if ( !(unsigned __int8)sub_614460(a2, 0) || 0.0 == sub_520EB0((_DWORD *)this[6], COERCE_FLOAT(&v19)) )
  {
    v23 = -1;
    sub_614140(&v19);
    return 0;
  }
  else
  {
    sub_613CE0(&v10, 4);
    sub_613CE0(v20, v10);
    sub_613CE0(&v10, 4);
    sub_613CE0(v20, v10);
    v8 = 0;
    sub_613CE0(&v8, 1);
    v9 = 0;
    sub_613CE0(&v9, 1);
    v12 = 0;
    sub_613CE0(&v12, 4);
    sub_613CE0(&v11, 4);
    for ( i = 0; i < v11; ++i )
    {
      sub_521420();
      LOBYTE(v23) = 1;
      sub_5209D0(v21, (int)&v19);
      LOBYTE(v23) = 0;
      nullsub_7(v22);
    }
    v7 = 0;
    sub_613CE0(&v7, 1);
    v6 = 0;
    if ( v7 )
    {
      do
      {
        v14 = 0;
        v15 = -1;
        LOBYTE(v23) = 2;
        sub_520850(&v13, &v19);
        LOBYTE(v23) = 0;
        if ( v14 )
          j_j__free(v14);
        ++v6;
      }
      while ( v6 < v7 );
    }
    sub_613CE0(&Block, 4);
    sub_613CE0(v18, 4);
    sub_613CE0(&v17, 4);
    sub_520B80(a3, (int)&v19);
    v23 = -1;
    sub_614140(&v19);
    return 1;
  }
}
