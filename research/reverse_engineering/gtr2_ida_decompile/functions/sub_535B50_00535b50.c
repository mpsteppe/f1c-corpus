char __usercall sub_535B50@<al>(int a1@<ecx>, char *a2@<edi>)
{
  char v3; // dl
  char v4; // al
  char v5; // cl
  char v6; // dl
  char v7; // cl
  int v8; // edx
  int v9; // eax
  int v10; // edi
  int v11; // ebp
  int v12; // ebp
  int v13; // edi
  int v14; // ebx
  int v15; // edi
  int v16; // eax
  char v18; // [esp-10h] [ebp-28h]
  int v19; // [esp-Ch] [ebp-24h]
  int v20; // [esp+4h] [ebp-14h]
  int v21; // [esp+8h] [ebp-10h]
  int v22; // [esp+Ch] [ebp-Ch]

  if ( !*(_BYTE *)(a1 + 95744) )
  {
    v19 = *(_DWORD *)(a1 + 95736);
    *(_BYTE *)(a1 + 95714) = 0;
    *(_BYTE *)(a1 + 95712) = 0;
    *(_BYTE *)(a1 + 95713) = 0;
    *(_BYTE *)(a1 + 95715) = 0;
    *(_BYTE *)(a1 + 95716) = 0;
    *(_BYTE *)(a1 + 95717) = 0;
    *(_DWORD *)(a1 + 95720) = 2;
    *(_DWORD *)(a1 + 95724) = 1;
    sub_533F30(a1, a2, v19);
    v3 = *(_BYTE *)(a1 + 95714);
    v4 = *(_BYTE *)(a1 + 95713);
    *(_BYTE *)(a1 + 95745) = *(_BYTE *)(a1 + 95712);
    v5 = *(_BYTE *)(a1 + 95715);
    *(_BYTE *)(a1 + 95746) = v3;
    v6 = *(_BYTE *)(a1 + 95717);
    *(_BYTE *)(a1 + 95748) = v5;
    v7 = *(_BYTE *)(a1 + 95716);
    *(_BYTE *)(a1 + 95750) = v6;
    *(_DWORD *)(a1 + 95752) = *(_DWORD *)(a1 + 95720);
    v8 = *(_DWORD *)(a1 + 95724);
    *(_BYTE *)(a1 + 95747) = v4;
    *(_DWORD *)(a1 + 95756) = v8;
    v18 = v4;
    v9 = *(_DWORD *)(a1 + 95736);
    *(_BYTE *)(a1 + 95749) = v7;
    sub_531DC0(a1 + 94760, v9, v18, v7);
    v10 = a1;
    v11 = 103;
    do
    {
      if ( *(_BYTE *)(v10 + 840) )
        sub_531DC0(v10, *(_DWORD *)(a1 + 95736), *(_BYTE *)(a1 + 95747), *(_BYTE *)(a1 + 95749));
      v10 += 920;
      --v11;
    }
    while ( v11 );
    if ( *(_DWORD *)(a1 + 95740) == 6 )
    {
      v12 = 0;
      v13 = 0;
      v22 = 0;
      while ( 1 )
      {
        v20 = 0;
        v21 = 0;
        if ( v13 )
          v14 = 920 * v13 + a1 - 920;
        else
          v14 = a1 + 94760;
        if ( *(_BYTE *)(v14 + 840) )
        {
          do
          {
            if ( v13 != v12 )
            {
              if ( v12 )
                v15 = 920 * v12 + a1 - 920;
              else
                v15 = a1 + 94760;
              if ( *(_BYTE *)(v15 + 840) )
              {
                if ( (int)(unsigned __int64)*(float *)(v15 + 792) > (int)(unsigned __int64)*(float *)(v14 + 792) )
                  ++v20;
                if ( (int)(unsigned __int64)*(float *)(v15 + 796) > (int)(unsigned __int64)*(float *)(v14 + 796)
                  && *(_DWORD *)(v15 + 844) == *(_DWORD *)(v14 + 844) )
                {
                  ++v21;
                }
              }
              v13 = v22;
            }
            ++v12;
          }
          while ( v12 < 104 );
          if ( v13 )
          {
            v16 = 920 * v13 + a1;
            *(_DWORD *)(v16 - 120) = v20;
            *(_DWORD *)(v16 - 116) = v21;
          }
          else
          {
            *(_DWORD *)(a1 + 95560) = v20;
            *(_DWORD *)(a1 + 95564) = v21;
          }
        }
        v22 = ++v13;
        if ( v13 >= 104 )
          break;
        v12 = 0;
      }
    }
    *(_BYTE *)(a1 + 95744) = 1;
  }
  return 0;
}
