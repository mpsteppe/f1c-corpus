char __thiscall sub_41C320(_DWORD *this, int a2, int a3, float a4, float a5, float a6, float a7, float a8, float a9)
{
  char result; // al
  int v11; // edi
  int v12; // ebx
  int v13; // eax
  float v14; // [esp+10h] [ebp-4h]

  result = 0;
  if ( *this )
  {
    if ( this[2] )
    {
      if ( this[3] )
      {
        if ( this[4] )
        {
          v11 = a2;
          if ( a2 )
          {
            v12 = a3;
            if ( a3 )
            {
              if ( sub_592CD0(a3) )
              {
                sub_5A0010(0.0, 0.0, 1.0, 1.0, 0xFFFFFF);
                sub_505D00(v12, v11, 0, 0, LODWORD(a4), 0, 1065353216, 1065353216, this[3]);
                sub_5A41F0(v11, &a2, &a3, 0);
                v13 = this[3];
                if ( a2 >= 0 )
                {
                  if ( a2 > *(_DWORD *)(v13 + 28) )
                    a2 = *(_DWORD *)(v13 + 28);
                }
                else
                {
                  a2 = 0;
                }
                if ( a3 >= 0 )
                {
                  if ( a3 > *(_DWORD *)(v13 + 32) )
                    a3 = *(_DWORD *)(v13 + 32);
                }
                else
                {
                  a3 = 0;
                }
                v14 = (double)a2 / (double)*(int *)(v13 + 28);
                a4 = (double)a3 / (double)*(int *)(v13 + 32);
                return sub_41C110(this, 0, -1, a5, a6, a7, a8, v14, a4, a9);
              }
              else
              {
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
