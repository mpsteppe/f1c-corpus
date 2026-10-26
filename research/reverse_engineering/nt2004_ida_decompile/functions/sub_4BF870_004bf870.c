void __stdcall sub_4BF870(char a1)
{
  int i; // esi
  int v2; // edi
  int v3; // eax

  if ( dword_7D5DA4 != 2 )
  {
    for ( i = 0; i < 43; ++i )
    {
      v2 = 0;
      if ( !a1 )
      {
        v3 = 0;
        if ( (int)NumOfElements > 0 )
        {
          while ( *(_DWORD *)(dword_75AAD0[v3] + 20884) != i + 1 )
          {
            if ( ++v3 >= (int)NumOfElements )
              goto LABEL_9;
          }
          v2 = dword_75AAD0[v3];
        }
      }
LABEL_9:
      sub_4BF8E0(i, v2);
    }
  }
}
