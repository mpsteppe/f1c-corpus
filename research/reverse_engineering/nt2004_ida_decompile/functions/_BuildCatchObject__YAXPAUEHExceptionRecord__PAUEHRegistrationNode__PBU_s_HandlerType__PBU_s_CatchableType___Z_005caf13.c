void __cdecl BuildCatchObject(
        struct EHExceptionRecord *a1,
        struct EHRegistrationNode *a2,
        const struct _s_HandlerType *a3,
        const struct _s_CatchableType *a4)
{
  TypeDescriptor *pType; // eax
  ptrdiff_t dispCatchObj; // eax
  void **v6; // edi
  void *pExceptionObject; // eax
  void *v8; // eax
  const void *v9; // eax
  void *v10; // [esp-8h] [ebp-30h]
  size_t sizeOrOffset; // [esp-4h] [ebp-2Ch]

  pType = a3->pType;
  if ( pType )
  {
    if ( pType->name[0] )
    {
      dispCatchObj = a3->dispCatchObj;
      if ( dispCatchObj )
      {
        v6 = (void **)((char *)&a2[1].pNext + dispCatchObj);
        if ( (a3->adjectives & 8) != 0 )
        {
          if ( _ValidateRead(a1->params.pExceptionObject, 1u) && _ValidateWrite(v6, 1u) )
          {
            pExceptionObject = a1->params.pExceptionObject;
            *v6 = pExceptionObject;
            v8 = AdjustPointer(pExceptionObject, &a4->thisDisplacement);
LABEL_8:
            *v6 = v8;
            return;
          }
LABEL_25:
          sub_5CB21D();
        }
        if ( (a4->properties & 1) != 0 )
        {
          if ( !_ValidateRead(a1->params.pExceptionObject, 1u) || !_ValidateWrite(v6, 1u) )
            goto LABEL_25;
          memcpy(v6, a1->params.pExceptionObject, a4->sizeOrOffset);
          if ( a4->sizeOrOffset == 4 && *v6 )
          {
            v8 = AdjustPointer(*v6, &a4->thisDisplacement);
            goto LABEL_8;
          }
        }
        else
        {
          v10 = a1->params.pExceptionObject;
          if ( a4->copyFunction )
          {
            if ( !_ValidateRead(v10, 1u) || !_ValidateWrite(v6, 1u) || !_ValidateExecute((FARPROC)a4->copyFunction) )
              goto LABEL_25;
            if ( (a4->properties & 4) != 0 )
            {
              AdjustPointer(a1->params.pExceptionObject, &a4->thisDisplacement);
              sub_5C15DA((int)v6, (int)a4->copyFunction);
            }
            else
            {
              AdjustPointer(a1->params.pExceptionObject, &a4->thisDisplacement);
              sub_5C15D3((int)v6, (int)a4->copyFunction);
            }
          }
          else
          {
            if ( !_ValidateRead(v10, 1u) || !_ValidateWrite(v6, 1u) )
              goto LABEL_25;
            sizeOrOffset = a4->sizeOrOffset;
            v9 = AdjustPointer(a1->params.pExceptionObject, &a4->thisDisplacement);
            memcpy(v6, v9, sizeOrOffset);
          }
        }
      }
    }
  }
}
