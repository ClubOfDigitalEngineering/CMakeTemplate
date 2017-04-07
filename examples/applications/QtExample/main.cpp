//Qt-Example-DonutChart
//http://doc.qt.io/qt-5/qtcharts-donutchart-main-cpp.html

#include <QtCharts>
using namespace QtCharts;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.35);
    series->append("Protein 4.2%", 4.2);
    QPieSlice *slice = series->append("Fat 15.6%", 15.6);
    slice->setExploded();
    slice->setLabelVisible();
    series->append("Other 23.8%", 23.8);
    series->append("Carbs 56.4%", 56.4);

    QChartView *chartView = new QChartView();
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setTitle("Donut with a lemon glaze (100g)");
    chartView->chart()->addSeries(series);
    chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
    chartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);
    chartView->chart()->legend()->setFont(QFont("Arial", 7));

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();


    return a.exec();
}