VERSION 5.00
Begin VB.Form OPCBatchSampleTest 
   Caption         =   "OPC Batch Client"
   ClientHeight    =   8685
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   11835
   Icon            =   "OPCBatchSampleTest.frx":0000
   LinkTopic       =   "OPC Batch Test"
   ScaleHeight     =   8685
   ScaleWidth      =   11835
   StartUpPosition =   3  'Windows Default
   Begin VB.Frame PropertiesFrame 
      Caption         =   "OPCSerrver - Properties"
      Height          =   855
      Left            =   120
      TabIndex        =   39
      Top             =   6540
      Width           =   2895
      Begin VB.CommandButton Prp_GetItemProperties 
         Caption         =   "Get Item Properties"
         Height          =   375
         Left            =   120
         TabIndex        =   40
         Top             =   300
         Width           =   2055
      End
   End
   Begin VB.CommandButton OtherOPCInterfaces 
      Caption         =   "Other OPC Interfaces"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   855
      Left            =   2820
      TabIndex        =   37
      Top             =   7740
      Width           =   1635
   End
   Begin VB.Frame Frame1 
      Height          =   1095
      Left            =   4980
      TabIndex        =   33
      Top             =   120
      Width           =   6615
      Begin VB.TextBox UserEntry 
         Height          =   285
         Left            =   1140
         TabIndex        =   35
         Top             =   720
         Width           =   5415
      End
      Begin VB.Label Label4 
         Alignment       =   2  'Center
         Caption         =   "Select line in the Log window below to initialize User Entry field"
         Height          =   255
         Left            =   180
         TabIndex        =   38
         Top             =   420
         Width           =   6375
      End
      Begin VB.Label Label3 
         Alignment       =   2  'Center
         Caption         =   "All commands that require string parameter will take it  from User Entry field"
         Height          =   255
         Left            =   60
         TabIndex        =   36
         Top             =   180
         Width           =   6495
      End
      Begin VB.Label CurrentSelection 
         Alignment       =   2  'Center
         Caption         =   "User Entry"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FF0000&
         Height          =   255
         Left            =   120
         TabIndex        =   34
         Top             =   720
         Width           =   975
      End
   End
   Begin VB.Frame OPCEnumerationSetsFrame 
      Caption         =   "OPCEnumerationSets"
      Height          =   1635
      Left            =   2340
      TabIndex        =   26
      Top             =   2400
      Width           =   2535
      Begin VB.TextBox EnumerationValue 
         Height          =   375
         Left            =   2040
         TabIndex        =   31
         Text            =   "3"
         Top             =   1140
         Width           =   375
      End
      Begin VB.TextBox EnumerationSetID 
         Height          =   375
         Left            =   2040
         TabIndex        =   30
         Text            =   "1"
         Top             =   720
         Width           =   375
      End
      Begin VB.CommandButton Enum_QueryEnumerationList 
         Caption         =   "QueryEnumerationList"
         Height          =   375
         Left            =   120
         TabIndex        =   29
         Top             =   720
         Width           =   1815
      End
      Begin VB.CommandButton Enum_QueryEnumeration 
         Caption         =   "QueryEnumeration"
         Height          =   375
         Left            =   120
         TabIndex        =   28
         Top             =   1140
         Width           =   1815
      End
      Begin VB.CommandButton Enum_QueryEnumerationSets 
         Caption         =   "QueryEnumerationSets"
         Height          =   375
         Left            =   120
         TabIndex        =   27
         Top             =   300
         Width           =   1815
      End
   End
   Begin VB.Frame BatchSummaryCollectionFrame 
      Caption         =   "BatchSummaryCollection"
      Height          =   1635
      Left            =   60
      TabIndex        =   22
      Top             =   2400
      Width           =   2055
      Begin VB.CommandButton BSum_ItemByNumber 
         Caption         =   "Item (Number)"
         Height          =   375
         Left            =   120
         TabIndex        =   25
         Top             =   1140
         Width           =   1215
      End
      Begin VB.TextBox ItemNumber 
         Height          =   375
         Left            =   1380
         TabIndex        =   24
         Text            =   "2"
         Top             =   1140
         Width           =   375
      End
      Begin VB.CommandButton BSum_ItemByName 
         Caption         =   "Item (Name)"
         Height          =   375
         Left            =   120
         TabIndex        =   23
         Top             =   420
         Width           =   1215
      End
      Begin VB.Label Label1 
         Alignment       =   2  'Center
         Caption         =   "see User Entry"
         ForeColor       =   &H00FF0000&
         Height          =   675
         Left            =   1320
         TabIndex        =   32
         Top             =   240
         Width           =   495
      End
   End
   Begin VB.Frame OPCBatchServerFrame 
      Caption         =   "OPCBatchServer"
      Height          =   1995
      Left            =   60
      TabIndex        =   17
      Top             =   180
      Width           =   1935
      Begin VB.CommandButton BSvr_GetDelimiter 
         Caption         =   "GetDelimiter"
         Height          =   375
         Left            =   120
         TabIndex        =   21
         Top             =   1500
         Width           =   1635
      End
      Begin VB.CommandButton BSvr_GetEnumerationSets 
         Caption         =   "GetEnumerationSets"
         Height          =   375
         Left            =   120
         TabIndex        =   20
         Top             =   1080
         Width           =   1635
      End
      Begin VB.CommandButton BSvr_GetBatchSummary 
         Caption         =   "GetBatchSummary"
         Height          =   375
         Left            =   120
         TabIndex        =   19
         Top             =   660
         Width           =   1635
      End
      Begin VB.CommandButton BSvr_GetOPCServer 
         Caption         =   "GetOPCServer"
         Height          =   375
         Left            =   120
         TabIndex        =   18
         Top             =   240
         Width           =   1635
      End
   End
   Begin VB.Frame BrowserFrame 
      Caption         =   "Browser"
      Height          =   1995
      Left            =   120
      TabIndex        =   5
      Top             =   4260
      Width           =   4755
      Begin VB.CommandButton Brw_GetBrowserProperties 
         Caption         =   "Show Properties"
         Height          =   375
         Left            =   120
         TabIndex        =   16
         Top             =   240
         Width           =   1335
      End
      Begin VB.CommandButton Brw_GetAccessPaths 
         Caption         =   "Get Access Paths"
         Height          =   375
         Left            =   3000
         TabIndex        =   14
         Top             =   660
         Width           =   1455
      End
      Begin VB.CommandButton Brw_GetItemID 
         Caption         =   "Get Item ID"
         Height          =   375
         Left            =   3000
         TabIndex        =   13
         Top             =   240
         Width           =   1455
      End
      Begin VB.CommandButton Brw_MoveTo 
         Caption         =   "Move To"
         Height          =   375
         Left            =   1560
         TabIndex        =   12
         Top             =   660
         Width           =   1335
      End
      Begin VB.CommandButton Brw_MoveToRoot 
         Caption         =   "Move To Root"
         Height          =   375
         Left            =   1560
         TabIndex        =   11
         Top             =   1500
         Width           =   1335
      End
      Begin VB.CommandButton Brw_MoveUp 
         Caption         =   "Move Up"
         Height          =   375
         Left            =   1560
         TabIndex        =   10
         Top             =   1080
         Width           =   1335
      End
      Begin VB.CommandButton Brw_MoveDown 
         Caption         =   "Move Down"
         Height          =   375
         Left            =   1560
         TabIndex        =   9
         Top             =   240
         Width           =   1335
      End
      Begin VB.CommandButton Brw_ShowBranches 
         Caption         =   "Show Branches"
         Height          =   375
         Left            =   120
         TabIndex        =   8
         Top             =   660
         Width           =   1335
      End
      Begin VB.CommandButton Brw_ShowLeafs 
         Caption         =   "Show Leafs"
         Height          =   375
         Left            =   120
         TabIndex        =   7
         Top             =   1080
         Width           =   1335
      End
      Begin VB.CommandButton Brw_ShowLeafsFlat 
         Caption         =   "Show Leafs Flat"
         Height          =   375
         Left            =   120
         TabIndex        =   6
         Top             =   1500
         Width           =   1335
      End
   End
   Begin VB.Frame OPCServerFrame 
      Caption         =   "OPCServer"
      Height          =   1995
      Left            =   2460
      TabIndex        =   1
      Top             =   180
      Width           =   1935
      Begin VB.CommandButton Svr_CreateBrowser 
         Caption         =   "Create Browser"
         Height          =   375
         Left            =   120
         TabIndex        =   15
         Top             =   1500
         Width           =   1635
      End
      Begin VB.CommandButton Svr_GetOPCServers 
         Caption         =   "GetOPCServers"
         Height          =   375
         Left            =   120
         TabIndex        =   4
         Top             =   240
         Width           =   1635
      End
      Begin VB.CommandButton Svr_Connect 
         Caption         =   "Connect"
         Height          =   375
         Left            =   120
         TabIndex        =   3
         Top             =   660
         Width           =   1635
      End
      Begin VB.CommandButton Svr_Disconnect 
         Caption         =   "Disconnect"
         Height          =   375
         Left            =   120
         TabIndex        =   2
         Top             =   1080
         Width           =   1635
      End
   End
   Begin VB.ListBox Log 
      BackColor       =   &H00E0E0E0&
      Height          =   7080
      Left            =   4980
      TabIndex        =   0
      Top             =   1380
      Width           =   6615
   End
End
Attribute VB_Name = "OPCBatchSampleTest"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
' (c) Copyright 2000 The OPC Foundation
' ALL RIGHTS RESERVED.
'
' DISCLAIMER:
'  This sample code is provided by the OPC Foundation solely to assist
'  in understanding the OPC Specifications and may be used
'  as set forth in the License Grant section of the OPC Specification.
'  This code is provided as-is and without warranty or support of any sort
'  and is subject to the Warranty and Liability Disclaimers which appear
'  in the printed OPC Specification.
'
' CREDITS:
'  This code was generously provided to the OPC Foundation by
'  Gregory Khrapunovich, ABB Automation
'
' CONTENTS:
' This code implements an OPC Batch Automation client
'
' Modification Log:
' Vers    Date       By    Notes
' ----  ----------- ----   -----
' 1.00  Sep 15,2000  GK    First Release
'

Option Explicit

' Declarations
Dim anOPCBABatchServer As OPCBABatchServer
' Depending on the type library either OPCServer or IOPCAutoServer is defined
' Dim anOPCServer As OPCServer
Dim anOPCServer As OPCServer
Dim anOPCBrowser As OPCBrowser
Dim anOPCBABatchSummmaryCollection As OPCBABatchSummaryCollection
Dim anOPCBAEnumerationSets As OPCBAEnumerationSets

Private Sub Aux_DisconnectFromServer()
    ' Disconnect OPC Batch Server
    Set anOPCBABatchSummmaryCollection = Nothing
    Set anOPCBAEnumerationSets = Nothing
    ' Disable batch server client calls
    BSvr_GetBatchSummary.Enabled = False
    BSvr_GetEnumerationSets.Enabled = False
    BSvr_GetDelimiter.Enabled = False
    BatchSummaryCollectionFrame.Enabled = False
    OPCEnumerationSetsFrame.Enabled = False
    
    ' Disconnect OPC Data Access Server
    If Not (anOPCServer Is Nothing) Then
        anOPCServer.Disconnect
    End If
    ' Disable buttons that cannot be pressed until server is connected
    Svr_Disconnect.Enabled = False
    Svr_CreateBrowser.Enabled = False
    BrowserFrame.Enabled = False
    PropertiesFrame.Enabled = False
End Sub

Private Sub Aux_LogResult(Optional EnsureVisible = False)
    If Err.number = 0 Then
        Log.AddItem ("   Success")
    Else
        Log.AddItem ("   Error " & Err.number & ": " & Err.Description)
    End If
    If (EnsureVisible) Then
        Aux_LogEnsureVisible
    End If
End Sub

Private Sub Aux_LogEnsureVisible()
'    Log.AddItem "============================="
    Log.AddItem ""
    Log.ListIndex = Log.ListCount - 1
End Sub

Private Sub OtherOPCInterfaces_Click()
    ' It should start another dialog with OPC Data Access client
    Log.AddItem "Other OPC Interfaces -- This OPC Batch sample client implements only the minimum subset"
    Log.AddItem "    of OPC Data Access that is necessary to test batch-specific functionmality."
    Log.AddItem "    Future implemetation may add standard OPC DA tests like OPC Groups etc."
    Aux_LogEnsureVisible
End Sub


Private Sub Brw_GetAccessPaths_Click()
    On Error Resume Next
    Dim itemID As String
    Dim anAccessPath As Variant
    itemID = UserEntry.Text
    Log.AddItem "OPCBrowser.GetAccessPaths(" & itemID & ")"
    Set anAccessPath = anOPCBrowser.GetAccessPaths(itemID)
    If Err.number <> 0 Then
        Aux_LogResult
    Else
        ' display the access paths
    End If
    Aux_LogEnsureVisible
End Sub

Private Sub Brw_GetBrowserProperties_Click()
    ' Get bowser properties
    Log.AddItem "   Browser properties:"
    Log.AddItem "Organization = " & anOPCBrowser.Organization
    Log.AddItem "Filter = " & anOPCBrowser.Filter
    Log.AddItem "Data Type = " & anOPCBrowser.DataType
    Log.AddItem "Access Rights = " & anOPCBrowser.AccessRights
    Log.AddItem "Current Position = " & anOPCBrowser.CurrentPosition
    Log.AddItem "Count = " & anOPCBrowser.Count
    Aux_LogEnsureVisible
End Sub

Private Sub Brw_GetItemID_Click()
    On Error Resume Next
    Dim leaf As String
    Dim itemID As String
    leaf = UserEntry.Text
    Log.AddItem "OPCBrowser.GetItemID(" & leaf & ")"
    itemID = anOPCBrowser.GetItemID(leaf)
    If Err.number <> 0 Then
        Aux_LogResult
    Else
        Log.AddItem itemID
    End If
    Aux_LogEnsureVisible
End Sub

Private Sub Brw_MoveDown_Click()
    On Error Resume Next
    Dim branch As String
    branch = UserEntry.Text
    Log.AddItem "OPCBrowser.MoveDown(" & branch & ")"
    anOPCBrowser.MoveDown branch
    Aux_LogResult
    Aux_LogEnsureVisible
End Sub

Private Sub Brw_MoveTo_Click()
    On Error Resume Next
    Dim branches(1) As String
    branches(1) = UserEntry.Text
    Log.AddItem "OPCBrowser.MoveTo(" & branches(1) & ")"
    anOPCBrowser.MoveTo branches
    Aux_LogResult
    Aux_LogEnsureVisible
End Sub

Private Sub Brw_MoveToRoot_Click()
    On Error Resume Next
    Log.AddItem "OPCBrowser.MoveToRoot"
    anOPCBrowser.MoveToRoot
    Aux_LogResult
    Aux_LogEnsureVisible
End Sub

Private Sub Brw_MoveUp_Click()
    On Error Resume Next
    Log.AddItem "OPCBrowser.MoveUp"
    anOPCBrowser.MoveUp
    Aux_LogResult
    Aux_LogEnsureVisible
End Sub

Private Sub Brw_ShowBranches_Click()
    Dim i As Integer
    Dim Count As Integer
    Log.AddItem "OPCBrowser.ShowBranches"
    anOPCBrowser.ShowBranches
    Aux_LogResult
    Count = anOPCBrowser.Count
    Log.AddItem "   Branches (Count = " & Count & "):"
    For i = 1 To Count
        Log.AddItem anOPCBrowser.Item(i)
    Next
    Aux_LogEnsureVisible
End Sub

Private Sub Brw_ShowLeafs_Click()
    Dim i As Integer
    Dim Count As Integer
    Log.AddItem "OPCBrowser.ShowLeafs(Flat = false)"
    anOPCBrowser.ShowLeafs (False)
    Aux_LogResult
    Count = anOPCBrowser.Count
    Log.AddItem "   Leafs (Count = " & Count & "):"
    For i = 1 To Count
        Log.AddItem anOPCBrowser.Item(i)
    Next
    Aux_LogEnsureVisible
End Sub

Private Sub Brw_ShowLeafsFlat_Click()
    Dim i As Integer
    Dim Count As Integer
    Log.AddItem "OPCBrowser.ShowLeafs(Flat = true)"
    anOPCBrowser.ShowLeafs (True)
    Aux_LogResult
    Count = anOPCBrowser.Count
    Log.AddItem "   All Leafs (Count = " & Count & "):"
    For i = 1 To Count
        Log.AddItem anOPCBrowser.Item(i)
    Next
    Aux_LogEnsureVisible
End Sub

Private Sub BSum_ItemByName_Click()
    Dim name As String
    name = UserEntry.Text
    Call BSum_Item(0, name)
End Sub

Private Sub BSum_ItemByNumber_Click()
    Dim number As Integer
    number = ItemNumber.Text
    Call BSum_Item(number, "")
End Sub

Private Sub BSum_Item(number As Integer, name As String)
   ' Test of OPCBatchSummaryCollection.Item()
    On Error Resume Next
    Dim anItem As OPCBABatchSummary
    If anOPCBABatchSummmaryCollection Is Nothing Then
        Log.AddItem "   Error getting Batch Summary:"
        Log.AddItem "    OPCBatchSummaryCollection is not defined"
        Aux_LogEnsureVisible
        Exit Sub
    End If
    
    If number > 0 Then
        Log.AddItem "OPCBatchSummmaryCollection.Item(" & number & ") - by number"
        Set anItem = anOPCBABatchSummmaryCollection.Item(number)
    Else
        Log.AddItem "OPCBatchSummmaryCollection.Item(" & name & ") - by name"
        Set anItem = anOPCBABatchSummmaryCollection.Item(name)
    End If
    If (Err.number = 0) Then
        ' Display batch summary
        Log.AddItem "   ID = " & anItem.ID
        Log.AddItem "   Description = " & anItem.Description
        Log.AddItem "   OPCItemID = " & anItem.OPCItemID
        Log.AddItem "   Master Recipe ID = " & anItem.MasterRecipeID
        Log.AddItem "   Batch Size = " & anItem.BatchSize
        Log.AddItem "   EU = " & anItem.EU
        Log.AddItem "   Execution State = " & anItem.ExecutionState
        Log.AddItem "   Execution Mode = " & anItem.ExecutionMode
        Log.AddItem "   Actual Start Time = " & anItem.ActualStartTime
        Log.AddItem "   Actual End Time = " & anItem.ActualEndTime
    Else
        Aux_LogResult
    End If
    Aux_LogEnsureVisible
    Set anItem = Nothing
End Sub

Private Sub BSvr_GetBatchSummary_Click()
    On Error Resume Next
    Dim Count As Integer, i As Integer
    Dim anItem As OPCBABatchSummary
    ' Release previous object
    Set anOPCBABatchSummmaryCollection = Nothing
    Log.AddItem "OPCBatchServer.GetOPCBatchSummmaryCollection"
    Set anOPCBABatchSummmaryCollection = anOPCBABatchServer.GetOPCBABatchSummaryCollection
    ' If connection succeeded, display server properties
    If (Err.number = 0) Then
        Count = anOPCBABatchSummmaryCollection.Count
        Log.AddItem "   Number of batches = " & Count
        For i = 1 To Count
            Set anItem = anOPCBABatchSummmaryCollection.Item(i)
            Log.AddItem anItem.ID
        Next
        BatchSummaryCollectionFrame.Enabled = True
    Else
        Aux_LogResult
    End If
    Aux_LogEnsureVisible
End Sub

Private Sub BSvr_GetDelimiter_Click()
    Dim delimiter As String
    delimiter = anOPCBABatchServer.delimiter
    Log.AddItem "OPCBatchServer.Delimiter = " & delimiter
    Aux_LogEnsureVisible
End Sub

Private Sub BSvr_GetEnumerationSets_Click()
    On Error Resume Next
    ' Release previous object
    Set anOPCBAEnumerationSets = Nothing
    Log.AddItem "OPCBatchServer.GetOPCEnumerationSets"
    Set anOPCBAEnumerationSets = anOPCBABatchServer.GetOPCBAEnumerationSets
    If Err.number = 0 Then
        OPCEnumerationSetsFrame.Enabled = True
    End If
    Aux_LogResult (True)
End Sub

Private Sub BSvr_GetOPCServer_Click()
    On Error Resume Next
    ' Release previous object
    Aux_DisconnectFromServer
    Set anOPCServer = Nothing
    Log.AddItem "OPCBatchServer.GetOPCServer"
    Set anOPCServer = anOPCBABatchServer.GetOPCServer
    If Err.number = 0 Then
        ' Enable server commands
        OPCServerFrame.Enabled = True
        ' Prohibit repetition of GetOPCServer command
        BSvr_GetOPCServer.Enabled = False
    End If
    Aux_LogResult (True)
    ' Initialize UserEntry field (for user convinience only)
    UserEntry.Text = "OPC.BatchSample.1"
End Sub

Private Sub Enum_QueryEnumeration_Click()
    On Error Resume Next
    Dim EnumSetID As Long, EnumValue As Long
    Dim EnumName As String
    
    EnumSetID = EnumerationSetID.Text
    EnumValue = EnumerationValue.Text
    
    Log.AddItem "OPCEnumerationSets.QueryEnumeration(" & EnumSetID & ", " & EnumValue & ")"
    EnumName = anOPCBAEnumerationSets.QueryEnumeration(EnumSetID, EnumValue)
    If Err.number <> 0 Then
        Aux_LogResult
    Else
        Log.AddItem "   " & EnumName
    End If
    Aux_LogEnsureVisible
End Sub

Private Sub Enum_QueryEnumerationList_Click()
    On Error Resume Next
    Dim Count As Long, i As Long
    Dim EnumSetID As Long
    Dim EnumValue() As Long, EnumName() As String
    
    EnumSetID = EnumerationSetID.Text
    
    Log.AddItem "OPCEnumerationSets.QueryEnumerationList(" & EnumSetID & ")"
    Call anOPCBAEnumerationSets.QueryEnumerationList(EnumSetID, Count, EnumValue, EnumName)
    If Err.number <> 0 Then
        Aux_LogResult
    Else
        For i = 1 To Count
            Log.AddItem "   " & EnumValue(i) & " = " & EnumName(i)
        Next
    End If
    Aux_LogEnsureVisible

End Sub

Private Sub Enum_QueryEnumerationSets_Click()
    On Error Resume Next
    Dim Count As Long, i As Long
    Dim EnumSetID() As Long, EnumSetName() As String
    
    Log.AddItem "OPCEnumerationSets.QueryEnumerationSets()"
    Call anOPCBAEnumerationSets.QueryEnumerationSets(Count, EnumSetID, EnumSetName)
    If Err.number <> 0 Then
        Aux_LogResult
    Else
        For i = 1 To Count
            Log.AddItem "   " & EnumSetID(i) & " = " & EnumSetName(i)
        Next
    End If
    Aux_LogEnsureVisible
End Sub

Private Sub Form_Initialize()
    On Error Resume Next
    Set anOPCBABatchServer = New OPCBABatchServer
    Aux_DisconnectFromServer
    OPCServerFrame.Enabled = False
End Sub

Private Sub Form_Terminate()
    Aux_DisconnectFromServer
    Set anOPCServer = Nothing
    Set anOPCBABatchServer = Nothing
    Set anOPCBrowser = Nothing
    Set anOPCBABatchSummmaryCollection = Nothing
    Set anOPCBAEnumerationSets = Nothing
End Sub

Private Sub Log_Click()
' Copy selected string into UserEntry window
    Dim i As Integer
    i = Log.ListIndex
    UserEntry.Text = Log.List(i)
End Sub

Private Sub Prp_GetItemProperties_Click()
' You must call QueryAvailableProperties before calling this function
    On Error Resume Next
    Dim anItemID As String
    Dim PropertyIDs() As Long
    Dim Descriptions() As String
    Dim Values() As Variant
    Dim Types() As Integer
    Dim Errors() As Long
    Dim Count As Long
    Dim i As Long
    
    anItemID = UserEntry.Text
    
    ' First query available properties
    Log.AddItem "OPCServer.QueryAvailableProperties(" & anItemID & ")"
    Call anOPCServer.QueryAvailableProperties(anItemID, Count, PropertyIDs, Descriptions, Types)
    If Err.number = 0 Then
        Log.AddItem "   Returned " & Count & " properties"
    Else
        Aux_LogResult (True)
        Exit Sub
    End If
    
    ' Then get property values
    Log.AddItem "OPCServer.GetItemProperties(" & anItemID & ", " & Count & ")"
    Call anOPCServer.GetItemProperties(anItemID, Count, PropertyIDs, Values, Errors)
    If Err.number = 0 Then
        For i = 1 To Count
            Log.AddItem Descriptions(i) & "(" & PropertyIDs(i) & ") = " & Values(i)
            If Errors(i) <> 0 Then
                Log.AddItem "   Error = " & Errors(i)
            End If
        Next
    Else
        Aux_LogResult (True)
    End If
    Aux_LogEnsureVisible
End Sub

Private Sub Svr_Connect_Click()
' Test OPCServer Connect method and properties
    On Error Resume Next
    Dim SelectedServer As String
    
    'Clean up
    Aux_DisconnectFromServer
    
    'Get program id and connect
    SelectedServer = UserEntry.Text
    Log.AddItem "OPCSetver.Connect(" & SelectedServer & ")"
    anOPCServer.Connect (SelectedServer)
    ' If connection succeeded, display server properties
    If (Err.number = 0) Then
        Log.AddItem "   Server properties:"
        Log.AddItem "Start Time = " & anOPCServer.StartTime
        Log.AddItem "Current Time = " & anOPCServer.CurrentTime
        Log.AddItem "Last Update Time = " & anOPCServer.LastUpdateTime
        Log.AddItem "Major Version = " & anOPCServer.MajorVersion
        Log.AddItem "Minor Version = " & anOPCServer.MinorVersion
        Log.AddItem "Build Number = " & anOPCServer.BuildNumber
        Log.AddItem "Venor Info = " & anOPCServer.VendorInfo
        Log.AddItem "Server State = " & anOPCServer.ServerState
        Log.AddItem "Locale ID = " & anOPCServer.LocaleID
        Log.AddItem "Bandwidth = " & anOPCServer.Bandwidth
 '       Log.AddItem "OPC Groups = " & anOPCServer.OPCGroups
 '       Log.AddItem "Public Group Names = " & anOPCServer.PublicGroupNames
        Log.AddItem "Server Name = " & anOPCServer.ServerName
        Log.AddItem "Server Node = " & anOPCServer.ServerNode
        Log.AddItem "Client Name = " & anOPCServer.ClientName
        ' OPCBatchServer property
         Log.AddItem "   Delimiter = " & anOPCBABatchServer.delimiter
        ' Enable OPCServer command
        Svr_CreateBrowser.Enabled = True
        Svr_Disconnect.Enabled = True
        ' Disable Connect command
        Svr_Connect.Enabled = False
        ' Enable Batch Server commands
        BSvr_GetBatchSummary.Enabled = True
        BSvr_GetEnumerationSets.Enabled = True
        BSvr_GetDelimiter.Enabled = True
        ' Enable Query Properties
        PropertiesFrame.Enabled = True
    Else
        Aux_LogResult
    End If
    Aux_LogEnsureVisible
End Sub

Private Sub Svr_CreateBrowser_Click()
' Get OPC Browser from OPC Server
    On Error Resume Next
    Log.AddItem "OPCServer.CreateBrowser"
    If Not (anOPCBrowser Is Nothing) Then
        Log.AddItem "   Browser already exist"
        Exit Sub
    End If
    Set anOPCBrowser = anOPCServer.CreateBrowser
    If anOPCBrowser Is Nothing Then
        Log.AddItem "   Browser not supported"
        Exit Sub
    End If
    Aux_LogResult
    If Err.number = 0 Then
        BrowserFrame.Enabled = True
    End If
    Aux_LogEnsureVisible
End Sub

Private Sub Svr_Disconnect_Click()
    Log.AddItem "Disconnect"
    Aux_DisconnectFromServer
    Svr_Connect.Enabled = True
    Aux_LogResult (True)
End Sub

Private Sub Svr_GetOPCServers_Click()
' Test OPCServer GetOPCServers method
    On Error Resume Next
    Dim AllOPCServers As Variant
    Dim i As Integer
    Log.AddItem "GetOPCServers"
    AllOPCServers = anOPCServer.GetOPCServers
    ' If succeeded, display the server list
    If (Err.number = 0) Then
        For i = LBound(AllOPCServers) To UBound(AllOPCServers)
            Log.AddItem (AllOPCServers(i))
        Next
    Else
        Aux_LogResult
    End If
    Aux_LogEnsureVisible
End Sub

