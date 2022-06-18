import xlrd
import datetime
def excel_table_byindex(file,by_index):
    starttime = datetime.datetime.now()
    data=xlrd.open_workbook(file)
    table = data.sheets()[by_index]
    nrows = table.nrows
    colnames = table.row_values(0)
    list = []
    for rownum in range(1,nrows):
        row = table.row_values(rownum)
        if row:
            app={}
            for i in range(len(colnames)):
                app[colnames[i]]=row[i]
            list.append(app)
    endtime = datetime.datetime.now() - starttime
    print(endtime)
    return list
def excel_table_byname(file,by_name):
    starttime = datetime.datetime.now()
    data=xlrd.open_workbook(file)
    table = data.sheet_by_name(by_name)
    nrows = table.nrows
    colnames = table.row_values(0)
    list = []
    for rownum in range(1,nrows):
        row = table.row_values(rownum)
        if row:
            app={}
            for i in range(len(colnames)):
                app[colnames[i]]=row[i]
            list.append(app)
    endtime = datetime.datetime.now() - starttime
    print(endtime)
    return list
import xlwt
def excel_write(xls,sheet,row,lst,text):
    workbook = xlwt.Workbook(encoding='utf-8')
    worksheet = workbook.add_sheet(sheet)
    worksheet.write(row,lst,text)
    workbook.save(xls)