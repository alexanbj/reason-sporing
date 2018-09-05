describe('Tracking view', function() {
  beforeEach(() => {
    cy.visit('/sporing');
  });

  it('should render the tracking page', () => {
    cy.get('form').should('be.visible');
  });

  it('should pre-populate the form with value from the url', () => {
    const parcelId = 'prepopulated-id';
    cy.visit(`/sporing/${parcelId}`);
    cy.get('input').should('have.value', parcelId);
  });

  it('should render the no packages found view', () => {
    cy.get('input').clear();
    cy.get('input').type('no-package-like-this');
    cy.get('#9af98f83-10c5-4067-bc84-20554b2827d8').should('be.visible');
  });
});
