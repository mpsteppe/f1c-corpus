int __thiscall sub_414FC0(int *this)
{
  int v2; // eax
  int v5; // ecx
  int v6; // eax
  int *v7; // ecx
  int v8; // edx
  int *v9; // ecx
  int v10; // eax
  char *v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v16; // [esp+Ch] [ebp-8h]

  if ( *this == 4 )
  {
    v2 = this[29];
    *((float *)this + 34) = dbl_7DA9C8 + *((float *)this + 34);
    *((float *)this + 33) = dbl_7DA9C8 + *((float *)this + 33);
    if ( !v2 )
    {
LABEL_3:
      *this = -1;
      return *this;
    }
    v16 = 0;
    while ( v16++ < 10 )
    {
      v5 = this[29];
      switch ( *(_DWORD *)(v5 + 40) )
      {
        case 2:
          if ( *(int *)(v5 + 24) > 0 )
          {
            v12 = rand();
            v13 = this[29];
            if ( (double)v12 * 0.000030518509 >= *(float *)(v13 + 12) )
            {
              *(_DWORD *)(v13 + 40) = 4;
            }
            else
            {
              if ( *(_DWORD *)(v13 + 36) == 10 )
                sub_437120(this + 5);
              *(_DWORD *)(this[29] + 40) = 3;
            }
            v14 = this[29];
            if ( --*(_DWORD *)(v14 + 24) < 0 )
              *(_DWORD *)(v14 + 24) = 0;
          }
          else
          {
LABEL_39:
            *(_DWORD *)(v5 + 40) = 4;
          }
          break;
        case 3:
          if ( *(float *)(v5 + 16) > (double)*((float *)this + 34) )
            return *this;
          switch ( *(_DWORD *)(v5 + 36) )
          {
            case 2:
              v7 = (int *)this[1];
              if ( !v7 )
                goto LABEL_3;
              sub_40C420(v7, 1);
              v8 = this[29];
              *((_BYTE *)this + 140) = 1;
              *(_DWORD *)(v8 + 40) = 4;
              break;
            case 3:
              v9 = (int *)this[1];
              if ( !v9 )
                goto LABEL_3;
              if ( *((_BYTE *)this + 140) )
                sub_40C420(v9, 0);
              v10 = this[29];
              *((_BYTE *)this + 140) = 0;
              *(_DWORD *)(v10 + 40) = 4;
              break;
            case 4:
              if ( this[1] )
              {
                v11 = (char *)sub_459B80(*(_DWORD *)(v5 + 44));
                sub_40C400((int ***)this[1], v11);
              }
              *(_DWORD *)(this[29] + 40) = 4;
              continue;
            case 5:
              if ( this[1] )
                sub_42DB60(*(_DWORD *)(v5 + 44));
              *(_DWORD *)(this[29] + 40) = 4;
              continue;
            case 6:
              this[31] = *(_DWORD *)(v5 + 44);
              *(_DWORD *)(v5 + 40) = 4;
              continue;
            case 7:
              if ( *(_DWORD *)(v5 + 44) == 2 )
                sub_41BD10(&unk_629328);
              *(_DWORD *)(this[29] + 40) = 4;
              continue;
            case 9:
              goto LABEL_39;
            case 0xA:
              if ( !sub_437130(this + 5) )
                return *this;
              *(_DWORD *)(this[29] + 40) = 4;
              break;
            case 0xB:
              *(_DWORD *)(this[29] + 40) = 4;
              return *this;
            case 0xC:
              *this = 5;
              *(_DWORD *)(v5 + 40) = 4;
              continue;
            default:
              return *this;
          }
          break;
        case 4:
          if ( *(_DWORD *)(v5 + 36) == 10 )
            sub_4373B0(this + 5);
          v6 = this[29];
          if ( *(_BYTE *)(v6 + 32) )
            this[34] = 0;
          if ( *(int *)(v6 + 24) > 0 )
          {
            *(_DWORD *)(v6 + 40) = 2;
          }
          else if ( !sub_414EB0(this) )
          {
            *this = -1;
            return *this;
          }
          break;
        default:
          return *this;
      }
    }
  }
  return *this;
}
